#include<stdio.h>
int main()
{
    long long int m,b;
    scanf("%I64d%I64d",&m,&b);
    long long int max=0;
    for(int x=0;x<=10000000;x++)
    {
        long long int term=m*b-x;
        if(term%m==0&&term>=0)
        {
            long long int y=term/m;
            long long int sum=(y+1)*x*(x+1)/2+(x+1)*y*(y+1)/2;
            if(sum>max)
                max=sum;
        }
    }
    printf("%I64d",max);
}