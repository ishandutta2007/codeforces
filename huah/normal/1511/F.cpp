#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
const int N=205,mod=998244353;
/*
 ----x
---
dp[len][i][j][5]
len1i1len2len-j,len
len 11e9
i 18
j 04

dp[len][i][j]->dp[len+x][s][k]

a graph,find the number a roads so that the tot length is m
//x<=5

\sum_{i=0}^{n-1} dp[m][i][0][0]
*/
void add(int &x,int y)
{
  x+=y;if(x>=mod) x-=mod;
}
struct node
{
  int a[205][205];
  node(){memset(a,0,sizeof(a));}
  node operator*(const node&o)const
  {
    node ans;
    for(int i=0;i<=204;i++)
      for(int j=0;j<=204;j++)
      for(int k=0;k<=204;k++)
      add(ans.a[i][j],1ll*a[i][k]*o.a[k][j]%mod);
    return ans;
  }
};
node qpow(node a,int n)
{
  node ans;
  for(int i=0;i<=204;i++) ans.a[i][i]=1;
  for(;n;n>>=1,a=a*a)
  if(n&1) ans=ans*a;
  return ans;
}
int tot,ids,id[42][5];
string f[42];
int n,m,p[8];
string s[8];
map<string,int>mp,vis;
bool ispre(string a,string b)
{
  for(int i=0;i<a.size();i++) if(a[i]!=b[i]) return false;
  return true;
}
int ways(string a,string b)
{
  string hs=a+"#"+b;
  if(mp.count(hs)) return mp[hs];
  string str=a+b;
  int dp[20];
  memset(dp,0,sizeof(dp));
  dp[0]=1;
  rep(i,0,str.size())
  {
    rep(j,0,n-1)
    if(i+s[j].size()<=str.size()&&(i!=0||s[j].size()>a.size()))
    {
      bool flag=true;
      for(int k=0;k<s[j].size();k++)
        if(s[j][k]!=str[i+k]) flag=false;
      if(flag) dp[i+s[j].size()]=(dp[i+s[j].size()]+dp[i])%mod;
    }
  }
  return mp[hs]=dp[str.size()];
}
void sol(int cas)
{
  sc(n,m);
  rep(i,0,n-1) cin>>s[i];
  vis[""]=0;f[0]="";
  rep(i,0,n-1)
  {
    string t="";
    rep(j,0,s[i].size()-1)
    {
      t+=s[i][j];
      if(!vis[t]) vis[t]=++tot,f[tot]=t;
    }
  }
  node A;
  rep(i,0,tot)
    rep(j,0,4) id[i][j]=ids++;
  rep(i,0,tot)
  {
    rep(j,1,4) add(A.a[id[i][j]][id[i][j-1]],1);
    rep(j,0,n-1)
    {
      string t="",tt=s[j];
      for(int k=0;k<s[j].size();k++)
      {
        t+=tt[0];
        tt.erase(0,1);
        if(vis.count(tt))
          add(A.a[id[i][0]][id[vis[tt]][s[j].size()-1]],ways(f[i],t));
      }
      if(vis.count(f[i]+s[j]))
        add(A.a[id[i][0]][id[vis[f[i]+s[j]]][s[j].size()-1]],1);
    }
  }
  A=qpow(A,m);
  out(A.a[id[0][0]][id[0][0]]);
}
int main() 
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  // scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/