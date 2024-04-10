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
const int N=3e5+5,mod=998244353;
int n,a,b;
vector<int>e[N];
bool lev[N],del[N];
void dfs(int u,int p)
{
	lev[u]=true;
	for(int v:e[u])
	if(v!=p)
	{
		dfs(v,u);
		lev[u]=false;
	}
	a+=lev[u];
}
void gfs(int u,int p)
{
	lev[u]=true;
	for(int v:e[u])
	if(v!=p)
	{
		gfs(v,u);
		if(lev[v]) lev[u]=false;
	}
	if(!lev[u]) b++;
	else a++;
	if(lev[u]&&u==1) b++;
}
void sol(int cas)
{
	sc(n);
	rep(i,1,n) e[i].clear();
	rep(i,1,n-1)
	{
		int u,v;sc(u,v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	a=0;b=0;
	gfs(1,0);
	out(a-(b-1));
}
int main()
{
//   freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  scanf("%d",&t);
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