#include<stdio.h>
#include<math.h>
int main()
{
double n,h;
scanf("%lf%lf",&n,&h);
double area=h/2,part=area/n,parts=part,height;
for(int i=0;i<n-1;i++)
{
height=sqrt(2*h*parts);
parts+=part;
printf("%lf\n",height);
}
}