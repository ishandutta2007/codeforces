#include <iostream>
#include <cstdio>
#define DMAX 100008
using namespace std;

long long a[DMAX], n, h, k, x;
long long ans;

int main()
{
    cin>>n>>h>>k;
    for(long long i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
    }
    long long c=0;

    a[n+1]=h+1;
    long long sum=0;

    for(long long i=1; i<=n; i++)
    {
        sum+=a[i];
        if(sum%k+a[i+1] > h)
            ans+=sum/k+(sum%k!=0), sum=0;
    }
    ans+=sum/k;
    ans+=((sum%k)!=0);
    cout<<ans<<'\n';

    return 0;
}