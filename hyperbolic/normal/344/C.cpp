#include <stdio.h>
int main()
{
    long long int a,b,count=0,c;
    scanf("%lld%lld",&a,&b);
    while(1)
    {
        if(a==0||b==0)
        {
            printf("%lld",count);
            return 0;
        }
        if(a==b)
        {
            printf("%lld",count+1);
            return 0;
        }
        else if(a>b)
        {
            count+=(a/b);
            a%=b;
        }
        else
        {
            //b/a=1/R+1 -> 1/R=(b-a)/a -> R=a/b-a;
            count+=(b/a);
            b%=a;
        }
    }
}