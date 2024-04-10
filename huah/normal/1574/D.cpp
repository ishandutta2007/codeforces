#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
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
#define inf 0x3f3f3f3f
const int N=3e5+5,mod=998244353;
struct node
{
  vector<int>vc;
  ll sum;
  bool operator<(const node&o)const
  {
    return sum<o.sum;
  }
};
map<vector<int>,bool>vis,xxx;
priority_queue<node>q;
int n,m,c[10];
vector<int>vc[10];
void sol(int cas)
{
  sc(n);
  vector<int>ans;
  ll res=0;
  rep(i,0,n-1)
  {
    sc(c[i]);
    rep(j,1,c[i])
    {
      int x;sc(x);
      vc[i].push_back(x);
    }
    ans.push_back(c[i]-1);
    res+=vc[i].back();
  }
  sc(m);
  rep(i,1,m)
  {
    vector<int>vc;
    rep(j,1,n)
    {
      int x;sc(x);vc.push_back(x-1);
    }
    xxx[vc]=true;
  }
  q.push({ans,res});
  while(!q.empty())
  {
    vector<int>u=q.top().vc;
    ll sum=q.top().sum;q.pop();
    if(!xxx.count(u))
    {
      rep(i,0,n-1)
        printf(i==n-1?"%d\n":"%d ",u[i]+1);
      return;
    }
    rep(i,0,n-1)
      if(u[i])
      {
        sum-=vc[i][u[i]];
        u[i]--;
        sum+=vc[i][u[i]];
        if(!vis.count(u))
        {
          vis[u]=true;
          q.push({u,sum});
        }
        sum-=vc[i][u[i]];
        u[i]++;
        sum+=vc[i][u[i]];
      }
  }
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
  return 0;
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/
/*
011010000111001
100101111000110

10101010101
10101010101

010101
010101
*/