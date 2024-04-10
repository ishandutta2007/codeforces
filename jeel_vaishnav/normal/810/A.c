#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
   float n,k;
   scanf("%f%f",&n,&k);
   int arrsize=n;
   float a[arrsize];
   for(int i=0;i<n;i++)
       scanf("%f",&a[i]);
   float avg,sum=0;
   for(int i=0;i<n;i++)
       sum+=a[i];
   int pseudo=n;
   while(1)
       {
       avg=sum/pseudo;
       if(avg>=k-0.5)
           break;
       pseudo++;
       sum+=k;
   }
   printf("%.0f",pseudo-n);
}