#include<stdio.h>
#include<string.h>
int main()
{
int n;
scanf("%d",&n);
int faces=0;
char shape[13];
for(int i=0;i<n;i++)
{
scanf("%s",shape);
if(shape[0]=='T')
faces+=4;
if(shape[0]=='C')
faces+=6;
if(shape[0]=='O')
faces+=8;
if(shape[0]=='D')
faces+=12;
if(shape[0]=='I')
faces+=20;
    //printf("%s\n%d\n",shape,faces);
}
printf("%d",faces);
}