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
const int N=3e5+5,mod=998244353;
int n,m,q;
map<pair<int,int>,bool>vis;
vector<pair<int,int>>dis[N];
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  sc(n,m);
  sc(q);
  bool sp=false;
  if(n>m) swap(n,m),sp=true;
  while(q--)
  {
    int x,y;sc(x,y);
    if(sp) swap(x,y);
    vis[{x,y}]=true;
  }
  dis[0].push_back({1,1});
  int ans=293892;
  bool flag=true;
  for(int i=0;flag;i++)
  {
    sort(dis[i].begin(),dis[i].end());
    for(int j=0;j<dis[i].size();j++)
    if(j==int(dis[i].size())-1||dis[i][j].first!=dis[i][j+1].first)
    {
      if(dis[i][j].first>=n&&dis[i][j].second>=m)
      {
        ans=i;
        flag=false;
        break;
      }
      int nx=dis[i][j].first+dis[i][j].second+vis.count({dis[i][j].first,dis[i][j].second});
      if(dis[i][j].second<m) dis[i+1].push_back({dis[i][j].first,min(m,nx)});
      if(dis[i][j].first<n) dis[i+1].push_back({min(n,nx),dis[i][j].second});
    }
  }
  out(ans);
}