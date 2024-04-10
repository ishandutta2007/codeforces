#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7,N=2e6+10;
int n;
char s[N],ans[N];
int tot;
ll hs[N],f[N];
ll qpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1) ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}
int geths(int y)
{
    return (hs[tot]-hs[tot-y]+mod)%mod*qpow(f[tot-y],mod-2)%mod;
}
int main()
{
    f[0]=1;
    for(int i=1;i<N;i++)
        f[i]=f[i-1]*101%mod;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        int l=strlen(s+1),j=1;
        ll res=0,pos=1;
        for(int j=1;j<=l;j++)
        {
            res=(res+(s[j]-48)*f[j])%mod;
            if(j<=tot&&res==geths(j)) pos=j+1;
        }
        while(pos<=l)
        {
            ans[++tot]=s[pos];
            hs[tot]=(hs[tot-1]+(s[pos]-48)*f[tot])%mod;
            pos++;
        }
    }
    ans[tot+1]='\0';
    printf("%s",ans+1);
}