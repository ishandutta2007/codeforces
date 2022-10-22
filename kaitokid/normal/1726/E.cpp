#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=998244353;
int prs[300009];
int ff[300009];
int p[600009];
int inv[6000009];
int pw(int x,int y){
if(y==0)return 1;
int u=pw(x,y/2);
u=(u*1LL*u)%mod;
if(y%2)u=(u*1LL*x)%mod;
return u;}
int c(int x,int y)
{
    int ans=p[x];
    ans=(ans*1LL*inv[y])%mod;
    ans=(ans*1LL*inv[x-y])%mod;
    return ans;
}
int ch(int x,int y)
{
    x-=2*y;
    y++;
    return c(x+y-1,x);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   p[0]=1;
   for(int i=1;i<=600000;i++)p[i]=(p[i-1]*1LL*i)%mod;
   inv[600000]=pw(p[600000],mod-2);
   for(int i=599999;i>=0;i--)
    inv[i]=(inv[i+1]*1LL*(i+1))%mod;
   prs[0]=1;
   for(int i=2;i<=300000;i+=2)
    prs[i]=((i-1)*2*1LL*prs[i-2])%mod;
   ff[0]=ff[1]=1;
   for(int i=2;i<=300000;i++)
   {
       ff[i]=ff[i-1];
       ll g=i-1;
       g*=ff[i-2];
       ff[i]=(ff[i]+g)%mod;
   }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll ans=0;
        for(int i=0;i*2<=n;i+=2)
        {
            ll d=ch(n,i);
            d=(d*prs[i])%mod;
            d=(d*ff[n-2*i])%mod;
            ans=(ans+d)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}