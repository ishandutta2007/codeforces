#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int lld;
lld n,m,k;
bool ok(lld x)
{
    lld ile=0;
    for(lld i=1;i<=n;i++)
    {
        ile+=min(x/i,m);
        if(ile>=k)return true;
    }
    return ile>=k;
}
int main()
{
    
    scanf("%lld %lld %lld",&n,&m,&k);
    lld pocz=1; lld kon=n*m;
    while(kon-pocz>1)
    {
        lld sr=(pocz+kon)/2LL;
        if(ok(sr))kon=sr;
        else pocz=sr;
    }
    if(ok(pocz))printf("%I64d\n",pocz);
    else printf("%I64d\n",kon);
}