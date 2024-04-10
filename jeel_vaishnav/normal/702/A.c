#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int a[n],max=1,length=1;
for(int i=0;i<n;i++)
	{
	scanf("%d",&a[i]);	
	}
for(int i=1;i<n;i++)
	{	
	if(a[i]>a[i-1])
	length++;
	else
	{
	if(max<length)
	max=length;
	length=1;
    }       
	}
    if(max<length)
	max=length;
printf("%d",max);
}