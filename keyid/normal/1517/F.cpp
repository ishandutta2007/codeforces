#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long LL;

const int MAXN=305,MOD=998244353,inv2=(MOD+1)/2;

vector <int> G[MAXN];
int n,lim,dep[MAXN],dp[MAXN][2][MAXN],tmp[2][MAXN],ans[MAXN];

void dfs2(int u,int fa)
{
	for (int v:G[u])
		if (v!=fa)
		{
			dep[v]=dep[u]+1;
			dfs2(v,u);
		}
}

int get_diameter()
{
	dep[1]=0;
	dfs2(1,0);
	int root=1;
	for (int i=2;i<=n;i++)
		if (dep[i]>dep[root])
			root=i;
	dep[root]=0;
	dfs2(root,0);
	int ret=0;
	for (int i=1;i<=n;i++)
		ret=max(ret,dep[i]);
	return ret;
}

void add(int &x,LL y)
{
	x=(x+y)%MOD;
}

int dfs1(int u,int fa)
{
	int du=0;
	for (int i=0;i<2;i++)
		for (int j=0;j<n;j++)
			dp[u][i][j]=0;
	dp[u][0][0]=dp[u][1][0]=1;
	for (int v:G[u])
		if (v!=fa)
		{
			int dv=dfs1(v,u);
			int ndu=min(max(du,dv+1),lim);
			for (int j=0;j<2;j++)
				for (int i=0;i<=ndu;i++)
					tmp[j][i]=0;
			for (int i=0;i<=du;i++)
				for (int j=0;j<=dv;j++)
				{
					add(tmp[0][max(i,j+1)],(LL)dp[u][0][i]*dp[v][0][j]);
					if (i+j+1<=lim)
					{
						add(tmp[1][i],(LL)dp[u][1][i]*dp[v][0][j]);
						add(tmp[1][j+1],(LL)dp[u][0][i]*dp[v][1][j]);
					}
					else
					{
						add(tmp[0][j+1],(LL)dp[u][1][i]*dp[v][0][j]);
						add(tmp[0][i],(LL)dp[u][0][i]*dp[v][1][j]);
					}
					add(tmp[1][min(i,j+1)],(LL)dp[u][1][i]*dp[v][1][j]);
				}
			du=ndu;
			for (int j=0;j<2;j++)
				for (int i=0;i<=du;i++)
					dp[u][j][i]=tmp[j][i];
			dp[u][0][lim]=0;
		}
	return du;
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	int dia=get_diameter()+1;
	ans[0]=1;
	for (int i=1;i<dia;i++)
	{
		lim=i;
		int d1=dfs1(1,0);
		for (int k=0;k<=d1;k++)
			(ans[i]+=dp[1][1][k])%=MOD;
	}
	int ret=0;
	for (int i=dia-1;i>=1;i--)
		ans[i]-=ans[i-1];
	for (int i=0;i<dia;i++)
		ret=(ret+(LL)(i-1)*ans[i])%MOD;
	ret=(ret+n)%MOD;
	if (ret<0)
		ret+=MOD;
	for (int i=0;i<n;i++)
		ret=(LL)ret*inv2%MOD;
	printf("%d\n",ret);
	return 0;
}