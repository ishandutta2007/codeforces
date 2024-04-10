#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=505,mod=1e9+7;
#define inf 0x3f3f3f3f
typedef long long ll;
ll qpow(ll a,ll n)
{
    ll ans=1;
    for(;n;n>>=1,a=a*a%mod)
    if(n&1) ans=ans*a%mod;
    return ans;
}
int n,m,k,r,c,x1,y1,x2,y2;
ll jiao(int x1,int y1,int x2,int y2,int r,int c)
{
    if(abs(x1-x2)>=r||abs(y1-y2)>=c) return 0;
    if(y2<y1)
        swap(x1,x2),swap(y1,y2);
    if(x1==x2&&y1==y2) return 1ll*r*c;
    if(x2<x1)
    {
        x2=x2+r-1;
        x2=x1+(r-x2);
    }
    int nr=x1+r-x2,nc=y1+c-y2;
    // cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<r<<' '<<c<<' '<<nr<<' '<<nc<<'\n';
    return 1ll*nr*nc;
}
int sol(int x1,int y1,int x2,int y2,int r,int c)
{
    // cout<<"X: "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<r<<' '<<c<<'\n';
    if(y2<y1)
        swap(x1,x2),swap(y1,y2);
    if(abs(x1-x2)>=r||abs(y1-y2)>=c) return qpow(k,1ll*r*c);
    if(x1==x2&&y1==y2) return qpow(k,1ll*r*c);
    if(x2<x1)
    {
        x2=x2+r-1;
        x2=x1+(r-x2);
    }
    int nr=x1+r-x2,nc=y1+c-y2;
    int ans=qpow(k,1ll*r*c-1ll*nr*nc*2+jiao(x1,y1,x2,y2,nr,nc));
    // cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<r<<' '<<c<<' '<<nr<<' '<<nc<<' '<<ans<<'\n';
    return 1ll*ans*sol(x1,y1,x2,y2,nr,nc)%mod;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d",&r,&c);
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    // cout<<sol(x1,y1,x2,y2,r,c)<<' '<<jiao(x1,y1,x2,y2,r,c)<<'\n';
    printf("%d\n",1ll*qpow(k,1ll*n*m-1ll*r*c*2+jiao(x1,y1,x2,y2,r,c))*sol(x1,y1,x2,y2,r,c)%mod);
}