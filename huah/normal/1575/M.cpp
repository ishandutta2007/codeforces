#include<bits/stdc++.h>
typedef unsigned long long ull;
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
void ary(int *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void ary(ll *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void oary(int *a,int n){rep(i,1,n) printf(i==n?"%d\n":"%d ",a[i]);}
void oary(ll *a,int n){rep(i,1,n) printf(i==n?"%lld\n":"%lld ",a[i]);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const int N=2005,mod=1e9+7;
int n,m,up[N][N],down[N][N];
char s[N][N];
vector<pair<int,int>>vc;
/*
  ki*x+bi=bj*x+bj
  (ki-kj)*x=bj-bi
  x=(bj-bi)/(ki-kj)
*/
bool judge(pair<int,int>&a,pair<int,int>&b,pair<int,int>&c)
{
  return 1ll*(c.second-a.second)*(a.first-b.first)<=1ll*(b.second-a.second)*(a.first-c.first);
}
ll cal(pair<int,int>&s,int x)
{
  return 1ll*s.first*x+s.second;
}
ll sol(int x)
{
  vc.clear();
  ll ans=0;
  rep(j,1,m)
  {
    ans+=j*j;
    pair<int,int>s;
    if(up[x][j]||down[x][j])
      s={-2*j,j*j};
    if(up[x][j]&&down[x][j])
    {
      int t=min(x-up[x][j],down[x][j]-x);
      s.second+=t*t;
    }
    else if(up[x][j])
    {
      int t=x-up[x][j];
      s.second+=t*t;
    }
    else if(down[x][j])
    {
      int t=down[x][j]-x;
      s.second+=t*t;
    }
    else continue;
    while(vc.size()>=2&&judge(vc[vc.size()-2],vc[vc.size()-1],s)) vc.pop_back();
    vc.push_back(s); 
  }
  reverse(vc.begin(),vc.end());
  rep(j,1,m)
  {
    while(vc.size()>=2&&cal(vc[vc.size()-1],j)>=cal(vc[vc.size()-2],j)) vc.pop_back();
    ans+=cal(vc.back(),j);
  }
  return ans;
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    sc(n,m);
    n++;m++;
    rep(i,1,n) sc(s[i]+1);
    rep(i,1,n)
      rep(j,1,m)
      {
        up[i][j]=up[i-1][j];
        if(s[i][j]=='1') up[i][j]=i;
      }
    nep(i,n,1)
      rep(j,1,m)
      {
        down[i][j]=down[i+1][j];
        if(s[i][j]=='1') down[i][j]=i;
      }
    ll ans=0;
    rep(i,1,n)
      ans+=sol(i);
  out(ans);
}