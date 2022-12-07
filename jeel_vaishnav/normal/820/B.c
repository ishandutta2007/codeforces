#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
  double n,a;
    scanf("%lf%lf",&n,&a);
    double min=100000;
    int min_i=0;
    for(int i=3;i<=n;i++)
    {
        double angle=(180*(i-2)-(i-2)*(180*(n-2)/n))/2;
        double check=angle-a;
        if(check<0)
            check=(-1)*check;
        if(check<min)
        {
            min=check;
            min_i=i;
        }
    }
    printf("2 1 %d",min_i);
}