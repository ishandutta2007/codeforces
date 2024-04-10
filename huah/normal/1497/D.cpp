#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=5005,mod=998244353;
#define inf 0x3f3f3f3f
int n,tag[N],s[N];
ll dp[N];
void update(ll &x,ll y){if(y>x) x=y;}
int main()
{
  // freopen("1.in","r",stdin);
  int t;sc(t);
  while(t--)
  {
    sc(n);
    rep(i,1,n) sc(tag[i]);
    rep(i,1,n) sc(s[i]);
    memset(dp,0,sizeof(dp));
    rep(i,1,n)
      nep(j,i-1,1)
      if(tag[i]!=tag[j])
    {
      ll a=dp[i],b=dp[j];
      update(dp[i],b+abs(s[i]-s[j]));
      update(dp[j],a+abs(s[i]-s[j]));
    }
    ll ans=0;
    rep(i,1,n) ans=max(ans,dp[i]);
    out(ans);
  }
}
/*
1 2 4 8 16 32 64
1->2->3->4->5
*/