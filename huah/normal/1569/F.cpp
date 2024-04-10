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
const int N=5e5+5,mod=998244353;
int n,m,k;
ll f[15],c[15][15];
bool e[15][15];
ll g[15];
ll ans;
ll st1,st2;
ll C(int n,int m)
{
	if(m==0||m==n) return 1;
	if(m==1) return n;
	if(c[n][m]) return c[n][m];
	return c[n][m]=C(n-1,m-1)+C(n-1,m);
}
vector<pair<int,int>>vc;
map<ll,bool>vis;
bool judge(vector<pair<int,int>>&vc)
{
	if(vis.count(st1)) return vis[st1];
	int up=(1<<(vc.size()))-1;
	bool dp[up+1][vc.size()];
	memset(dp,false,sizeof(dp));
	for(int i=0;i<vc.size();i++) dp[1<<i][i]=true;
	for(int i=0;i<up;i++)
		for(int j=0;j<vc.size();j++)
		if(dp[i][j])
		{
			for(int k=0;k<vc.size();k++)
				if(!(i>>k&1))
				{
					if(e[vc[k].first][vc[j].first]&&e[vc[k].second][vc[j].second]||e[vc[k].first][vc[j].second]&&e[vc[k].second][vc[j].first])
						dp[i|(1<<k)][k]=true;
				}
		}
	bool ans=false;
	for(int i=0;i<vc.size();i++)
		if(e[vc[i].first][vc[i].second])
		ans|=dp[up][i];
	return vis[st1]=ans;
}
set<ll>ok;
void cal(vector<pair<int,int>>&vc,int mx)
{
	if(judge(vc))
	{
		if(!ok.count(st2))
		{
			ans+=C(k,mx+1)*f[mx+1];
			ok.insert(st2);
		}
	}
}
void dfs(int up,int mx)
{
	if(up==0)
	{
		cal(vc,mx);
		return;
	}
	for(int i=0;i<n;i++)
		if(up>>i&1)
		{
			for(int j=i+1;j<n;j++)
				if(up>>j&1)
				{
					st1+=(i+1)*g[vc.size()<<1];
					st1+=(j+1)*g[vc.size()<<1|1];
					vc.push_back({i+1,j+1});
					int nst=up^(1<<i)^(1<<j);
					for(int s=0;s<=mx+1&&s<k;s++)
					{
						st2+=(s+1)*g[i];
						st2+=(s+1)*g[j];
						dfs(nst,max(s,mx));
						st2-=(s+1)*g[i];
						st2-=(s+1)*g[j];
					}
					vc.pop_back();
					st1-=(i+1)*g[vc.size()<<1];
					st1-=(j+1)*g[vc.size()<<1|1];
				}
			break;
		}
}
void ways()
{
	ll dp[13][13];
	memset(dp,0,sizeof(dp));
	dp[1][0]=1;
	for(int i=1;i<12;i++)
		for(int j=0;j<12;j++)
		for(int k=0;k<=j+1&&k<12;k++)
		dp[i+1][max(j,k)]+=dp[i][j];
	ll ans=0;
	for(int k=0;k<12;k++) ans+=dp[12][k];
	out(ans);
}
void sol(int cas)
{
	f[0]=g[0]=1;
	for(int i=1;i<15;i++) f[i]=f[i-1]*i,g[i]=g[i-1]*13;
	sc(n,m,k);
	rep(i,1,m)
	{
		int x,y;sc(x,y);e[x][y]=e[y][x]=true;
	}
	int up=(1<<n)-1;
	dfs(up,-1);
	out(ans);
}
int main()
{
//   freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
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