#include<stdio.h>
int main()
{
int n,h;
scanf("%d%d",&n,&h);
int hi,width=0;
for(int i=0;i<n;i++)
{
scanf("%d",&hi);
if(hi>h)
width+=2;
else
width++;
}
printf("%d",width);
}