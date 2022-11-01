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
const int N=3e5+5,mod1=1e9+7,mod2=998244353;
#define inf 0x3f3f3f3f
int n,lg[N];
ll a[2][N];
struct st_table
{
  ll dp[N][20];
  int n;
  void build()
  {
    for(int i=1;1<<i<=n;i++)
      for(int j=1;j+(1<<i)-1<=n;j++)
      dp[j][i]=min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
  }
  void init(int _n){n=_n;for(int i=1;i<=n;i++) dp[i][0]=1e18;}
  void ins(int x,ll v){if(v<dp[x][0])dp[x][0]=v;}
  ll query(int l,int r){int k=lg[r-l+1];return min(dp[l][k],dp[r-(1<<k)+1][k]);}
}st[2][2];
bool judge(int l,int r)
{
  return st[1][0].query(l,r)>=a[1][l-1]&&st[0][1].query(l,r)>=a[0][l-1];
}
vector<pair<ll,int>>vc[N];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    for(int i=1;i<N;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i),lg[i-1]--;
    int t;
    sc(t);
    while(t--)
    {
        sc(n);
        rep(i,1,n) sc(a[0][i]);
        rep(i,0,n) vc[i].clear();
        for(int i=2;i<=n;i+=2) a[0][i]=-a[0][i];
        for(int i=1;i<=n;i++) a[1][i]=-a[0][i];
        rep(i,1,n) a[0][i]+=a[0][i-1],a[1][i]+=a[1][i-1];
        st[0][1].init(n);st[1][0].init(n);
        rep(i,1,n)
        {
          if(i&1)
            st[0][1].ins(i,a[0][i]);
          else st[1][0].ins(i,a[1][i]);
        }
        st[0][1].build();st[1][0].build();
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
          int j=i-1,k=1<<lg[n-(i-1)];
          while(k)
          {
            if(j+k<=n&&judge(i,j+k)) j+=k;
            k>>=1;
          }
          if(i<=j)
          {
            vc[i-1].push_back({a[0][i-1],-1});
            vc[j].push_back({a[0][i-1],1});
          }
        }
        map<ll,int>vis;
        vis[0]=1;
        rep(i,0,n)
        {
          vis[a[0][i]]++;
          for(pair<ll,int>x:vc[i])
            ans+=vis[x.first]*x.second;
        }
        printf("%lld\n",ans);
    }
}