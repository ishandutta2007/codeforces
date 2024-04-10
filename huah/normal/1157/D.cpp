#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll n,k,a[N];
int main()
{
    scanf("%lld%lld",&n,&k);
    if(k==1) {printf("YES\n%lld\n",n);return 0;}
    ll f=n;
    ll a1=0;
    for(ll i=1;;i++)
    {
        if(n>=i*k+k*(k-1)/2)
        {
            ll sum=0;
            for(ll j=1,t=i;j<=k;j++,t<<=1)
            {
                sum+=t;
                if(sum>=n) break;
            }
            if(sum>=n) {a1=i;break;}
        }
        else break;
    }
    if(!a1) {printf("NO\n");return 0;}
    printf("YES\n");
    for(ll i=1,t=a1;i<=k;i++,t++)
        a[i]=t;
    n-=a1*k+k*(k-1)/2;
    ll p=0;
    for(ll i=1,t=a1;i<=k;i++,t<<=1)
    {
        t=min(f,t);
        a[i]+=p;
        ll s=min(t-a[i],n/(k-i+1));
        n-=s*(k-i+1);
        a[i]+=s;
        p+=s;
    }
    for(ll i=1;i<=k;i++)
        printf(i==k?"%lld\n":"%lld ",a[i]);
}