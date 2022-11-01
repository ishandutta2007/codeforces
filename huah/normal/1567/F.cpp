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
#define fi first
#define se second
const int N=505,mod=1e9+7;
vector<int>e[N*N];
int n,m,ans[N][N];
char s[N][N];
int id(int i,int j){return (i-1)*m+j;}
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int vis[N*N];
void dfs(int u,int val)
{
	vis[u]=val;
	int x=(u-1)/m+1,y=(u-1)%m+1;
	ans[x][y]=val;
	for(int v:e[u])
		if(!vis[v])
		dfs(v,val==1?4:1);
		else assert(vis[v]!=vis[u]);
}
void sol(int cas)
{
	sc(n,m);
	rep(i,1,n) sc(s[i]+1);
	rep(i,1,n)
		rep(j,1,m)
		if(s[i][j]=='X')
		{
			vector<int>g;
			for(int k=0;k<4;k++)
			{
				int ii=i+dx[k];
				int jj=j+dy[k];
				if(s[ii][jj]=='.') g.push_back(id(ii,jj));
			}
			if(g.size()&1)
			{
				printf("NO\n");
				return;
			}
			if(g.size()==2)
			{
				int x=g[0],y=g[1];
				e[x].push_back(y);
				e[y].push_back(x);
			}
			else if(g.size()==4)
			{
				e[id(i+1,j)].push_back(id(i,j-1));
				e[id(i,j-1)].push_back(id(i+1,j));
				e[id(i-1,j)].push_back(id(i,j+1));
				e[id(i,j+1)].push_back(id(i-1,j));
			}
			//
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(s[i][j]=='.'&&!vis[id(i,j)])
		dfs(id(i,j),1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(s[i][j]=='X')
		{
			for(int k=0;k<4;k++)
			{
				int ii=i+dx[k];
				int jj=j+dy[k];
				if(s[ii][jj]=='.')
				ans[i][j]+=ans[ii][jj];
			}
		}
	printf("YES\n");
	rep(i,1,n)
		rep(j,1,m)
		printf(j==m?"%d\n":"%d ",ans[i][j]);
}
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
  ast(t,1,10);
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