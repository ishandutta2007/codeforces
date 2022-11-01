#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll ppow[100005],a[100005];
char s[100005];
int main()
{
    ll k=1;
    ppow[0]=k;
    for(int i=1;i<=100000;i++)
        ppow[i]=k*2%mod,k=k*2%mod,ppow[i]=(ppow[i-1]+ppow[i])%mod;
    ll n,q;
    scanf("%lld%lld",&n,&q);
    scanf("%s",s+1);
    k=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1') k++;
        a[i]=k;
    }
    while(q--)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        ll cot=a[r]-a[l-1];
        ll p=r-l+1-cot;
        if(p==0)
            printf("%lld\n",ppow[cot-1]);
        else printf("%lld\n",(ppow[cot+p-1]-ppow[p-1]+mod)%mod);
    }
}