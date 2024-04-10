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
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=1e5+5;
int tot,p[N];
ll phi[N];
vector<ll>f1[N],f2[N];
bool vis[N];
void init()
{
  phi[1]=1;
  for(int i=2;i<=100000;i++)
  {
    if(!vis[i]) p[++tot]=i,phi[i]=i-1;
    for(int j=1;j<=tot&&i*p[j]<=100000;j++)
    {
      vis[i*p[j]]=true;
      if(i%p[j]==0)
      {
        phi[i*p[j]]=phi[i]*p[j];
        break;
      }
      phi[i*p[j]]=phi[i]*phi[p[j]];
    }
  }
  for(int i=2;i<=100000;i++) phi[i]+=phi[i-1];
  for(int i=1;i<=100000;i++)
  {
    vector<pair<int,ll>>sum;
    for(int l=1,r;l<=i;l=r+1)
    {
      r=i/(i/l);
      sum.push_back({i/l,1ll*(r-l+1)*phi[i/l]});
    }
    for(int j=int(sum.size())-2;j>=0;j--)
      sum[j].second+=sum[j+1].second;
    f1[i].resize(sqrt(i)+3);
    f2[i].resize(sqrt(i)+3);
    for(int j=int(sum.size())-1;j>=0;j--)
    {
      if(1ll*sum[j].first*sum[j].first<=i)
        f1[i][sum[j].first]=sum[j].second;
      else f2[i][i/sum[j].first]=sum[j].second;
    }
  }
}
ll c(int l,int r)
{
  if(l>r) return 0;
  ll ans=0;
  int rr=r/(r/l);
  if(rr<r)
  {
    int g=r/(rr+1);
    ans+=1ll*g*g<=r?f1[r][g]:f2[r][r/g];
  }
  return 1ll*(rr-l+1)*phi[r/l]+ans;
}
ll dp[17][N];
struct node
{
  int p,l,r;
}q[N];
int l,r;
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  init();
  memset(dp,0x3f3f3f3f3f3f3f3fll,sizeof(dp));
  dp[0][0]=0;
  function<ll(int,int,int)>get=[&](int i,int x,int y)
  {
    return dp[i][x]+c(x+1,y);
  };
  for(int i=1;i<=16;i++)
  {
    q[l=r=1]={0,0,100000};
    for(int j=0;j<=100000;j++)
    {
      dp[i][j]=get(i-1,q[l].p,j);
      assert(q[l].l==j);
      if(q[l].l==q[l].r) l++;
      else q[l].l++;
      while(get(i-1,j,q[r].l)<get(i-1,q[r].p,q[r].l)) r--;
      if(l<=r)
      {
        int le=q[r].l,ri=q[r].r;
        while(le<ri)
        {
          int m=(le+ri+1)>>1;
          if(get(i-1,j,m)<get(i-1,q[r].p,m)) ri=m-1;
          else le=m;
        }
        q[r].r=le;  
        if(le<100000)
          q[++r]={j,le+1,100000};
      }
      else q[++r]={j,j+1,100000};
    }
  }
  int t;sc(t);
  while(t--)
  {
    int n,k;sc(n,k);
    if(k>=20||(1<<k)>n) out(n);
    else out(dp[k][n]);
  }
}