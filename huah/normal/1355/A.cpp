#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,mn,mx;
void getdig(ll x)
{
    mn=9;mx=0;
    while(x)
    {
        mn=min(mn,x%10);
        mx=max(mx,x%10);
        x/=10;
    }
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&k);
        k--;
        while(k)
        {
            getdig(n);
            if(mn*mx==0) break;
            n=n+mn*mx;
            k--;
        }
        printf("%lld\n",n);
    }
}