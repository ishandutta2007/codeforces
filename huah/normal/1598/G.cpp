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
const int N=5e5+5;
const int bs=8;
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
char s[N],x[N];
int n,m,hs[bs][N],p[bs][N];
vector<int>mod,fs;
bool judge(int x)
{
  for(int i=2;i*i<=x;i++)
    if(x%i==0) return false;
  return true;
}
int getprim()
{
  int x=rdint(900000000,1030000000);
  while(!judge(x)) x++;
  return x;
}
void cal(int *hs,int *p,int mod)
{
  int ss=0;
  for(int i=1;x[i];i++)
    ss=(1ll*ss*10+x[i]-'0')%mod;
  fs.push_back(ss);
  p[0]=1;
  for(int i=1;i<=n;i++)
  {
    hs[i]=(1ll*hs[i-1]*10+s[i]-'0')%mod;
    p[i]=1ll*p[i-1]*10%mod;
  }
}
vector<int>geths(int l,int r)
{
  vector<int>ans;
  for(int i=0;i<bs;i++)
    ans.push_back((hs[i][r]-1ll*hs[i][l-1]*p[i][r-l+1]%mod[i]+mod[i])%mod[i]);
  return ans;
}
void getlcp(char *a,char *b,int n,int m,int *nex,int *ans)
{
    nex[1]=n;
    int id=0,r=0;
    for(int i=2;i<=n;i++)
    {
        if(i<r) nex[i]=min(nex[i-id+1],r-i);
        else nex[i]=0;
        while(i+nex[i]<=n&&a[i+nex[i]]==a[nex[i]+1]) nex[i]++;
        if(i+nex[i]>r)
            id=i,r=i+nex[i];
    }
    id=r=0;
    for(int i=1;i<=m;i++)
    {
        if(i<r) ans[i]=min(nex[i-id+1],r-i);
        else ans[i]=0;
        while(i+ans[i]<=m&&ans[i]+1<=n&&b[i+ans[i]]==a[ans[i]+1]) ans[i]++;
        if(i+ans[i]>r)
            id=i,r=i+ans[i];
    }
}
int lx[N],ls[N];
void sol(int cas)
{
  sc(s+1);
  sc(x+1);
  n=strlen(s+1);
  m=strlen(x+1);
  getlcp(x,s,m,n,lx,ls);
  for(int i=0;i<bs;i++)
  { 
    mod.push_back(getprim());
    cal(hs[i],p[i],mod[i]);
  }
  vector<pair<int,int>>ans1;
  vector<pair<int,int>>ans2;
  if(m-1>=1)
  {
    for(int i=1;i+2*(m-1)-1<=n;i++)
    {
      vector<int>x=geths(i,i+m-2);
      vector<int>y=geths(i+m-1,i+2*(m-1)-1);
      for(int j=0;j<bs;j++) x[j]=(x[j]+y[j])%mod[j];
      if(x==fs)
      {
        ans1.push_back({i,i+m-2});
        ans2.push_back({i+m-1,i+2*(m-1)-1});
      }
    }
  }
  for(int i=1;i+m-1<=n;i++)
  {
      int len=m-ls[i];
      vector<int>x=geths(i,i+m-1);
      if(len>=1)
      {
        if(i+m+len-1<=n)
        {
            vector<int>y=geths(i+m,i+m+len-1);
            for(int j=0;j<bs;j++) y[j]=(y[j]+x[j])%mod[j];
            if(y==fs) ans1.push_back({i,i+m-1}),ans2.push_back({i+m,i+m+len-1});
        }
        if(i-len>=1)
        {
            vector<int>y=geths(i-len,i-1);
            for(int j=0;j<bs;j++) y[j]=(y[j]+x[j])%mod[j];
            if(y==fs) ans1.push_back({i-len,i-1}),ans2.push_back({i,i+m-1});
        }
      }
      len--;
      if(len>=1)
      {
        if(i+m+len-1<=n)
        {
            vector<int>y=geths(i+m,i+m+len-1);
            for(int j=0;j<bs;j++) y[j]=(y[j]+x[j])%mod[j];
            if(y==fs) ans1.push_back({i,i+m-1}),ans2.push_back({i+m,i+m+len-1});
        }
        if(i-len>=1)
        {
            vector<int>y=geths(i-len,i-1);
            for(int j=0;j<bs;j++) y[j]=(y[j]+x[j])%mod[j];
            if(y==fs) ans1.push_back({i-len,i-1}),ans2.push_back({i,i+m-1});
        }
      }
  }
//   assert(ans1.size()&&ans2.size());
  printf("%d %d\n",ans1[0].first,ans1[0].second);
  printf("%d %d\n",ans2[0].first,ans2[0].second);
}
int main()
{
  // freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
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