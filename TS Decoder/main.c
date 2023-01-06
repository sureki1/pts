#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>


unsigned char rawdata[30] = {0,};
int readdata[6] = { 0, };

unsigned short a;
unsigned short b;
unsigned int c;
int i = 0;
int j = 0;
unsigned char* temp = NULL;
unsigned char* str2 = NULL;


int main()
{
	FILE* read1;

	FILE* read2;

	read1 = fopen("PTS.txt", "w");

	read2 =	fopen("221227_1.csv", "r");

	for (i = 0; i < 210000; i++)
	{

		j = 0;

		fgets(rawdata, 30, read2);

		//printf("%d\t", rawdata[j]);

		if (rawdata[j] != 10) {



			temp = strtok_s(rawdata, "\n", &str2);
			//temp = strtok_s(temp, 0x0A, &str2);

			temp = strtok(temp, ",");

			while (temp != NULL) {

				readdata[j] = atoi(temp);

				if (readdata[j] != 0) {
					//printf("%d\t", readdata[0]);
					//printf("%s\t", temp);
					/*printf("%d\t", readdata[j]);

					if (readdata[j] <= 0) {

						readdata[j] = -readdata[j];
					}*/

					//printf("%d\t", readdata[j]);


					temp = strtok(NULL, ",");

					j++;

				}

				else {
					temp = strtok(NULL, ",");

					j++;
				}
			}

		}

		if (readdata[0] == 80 &&readdata[1] == 21) {

			a = ((unsigned short)readdata[2] << 8) + (unsigned short)readdata[3];

			a = a >> 1;

			//printf("%d\n", a);
			//printf("%d\t", readdata[2]);

			b = ((unsigned short)readdata[4] << 8) + (unsigned short)readdata[5];

			b = b >> 1;

			printf("%d\n", b);

			c = (unsigned int)a << 15 | (unsigned int)b;

			//printf("\n%d\n", c);

			if (c == 861838984)
			{

				printf("\n%d\n", c);
			}

			fprintf(read1, "%d\n", c);
			//fprintf(read1, "%d\t", readdata[0]);

		}
	}

	

	fclose(read2);
	
	fclose(read1);

	return 0;

}



