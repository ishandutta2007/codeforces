#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    long long n,a,b,ma,mb,ms=LLONG_MAX;
    scanf("%I64d%I64d%I64d",&n,&a,&b);
    n*=6;
    //printf("%I64d\n",ms);
    if (a*b>=n)
    {
        printf("%I64d\n%I64d %I64d",a*b,a,b);
        return 0;
    }
    bool flag=false;
    if (a>b)
    {
        flag=true;
        long long t=b;
        b=a;
        a=t;
    }
    long long maxa=sqrt(n)+1;
    for (long long i=a;i<=maxa;i++) 
    {
        long long t=n%i?n/i+1:n/i;
        t=max(t,b);
        if (i*t<=ms)
        {
            ms=i*t;
            ma=i;mb=t;
        }
    }
    if (flag)
    {
        long long t=ma;
        ma=mb;
        mb=t;
    }
    printf("%I64d\n%I64d %I64d",ms,ma,mb);
    return 0;
}