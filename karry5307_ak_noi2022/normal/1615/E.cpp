#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> ed[300000];

int dep[300000],son[300000],top[300000];
void dfs_bas(int u,int f)
{
	dep[u]=dep[f]+1,son[u]=u;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];if(v==f)continue;dfs_bas(v,u);
		if(dep[son[v]]>dep[son[u]])son[u]=son[v];
	}
	top[son[u]]=u;
}

int maxn_b[300000];

const long long INF=1e18;

int main()
{
	int n=0,k=0;scanf("%d%d",&n,&k);for(int i=1,u=0,v=0;i<n;i++){scanf("%d%d",&u,&v);ed[u].push_back(v),ed[v].push_back(u);}
	dfs_bas(1,0);
	vector<int> LF;
	for(int i=2;i<=n;i++)
	{
		if(ed[i].size()==1)
		{
			LF.push_back(dep[i]-dep[top[i]]+1);//printf("%d %d\n",i,dep[i]-dep[top[i]]+1);
		}
	}
	sort(LF.begin(),LF.end());reverse(LF.begin(),LF.end());
	for(int i=1;i<=LF.size();i++)maxn_b[i]=maxn_b[i-1]+LF[i-1];for(int i=LF.size()+1;i<=n;i++)maxn_b[i]=maxn_b[i-1];
	for(int i=0;i<=n;i++)maxn_b[i]=n-maxn_b[i];
	long long ans=-INF;
	for(int i=0;i<=k;i++)
	{
		int b=min(maxn_b[i],n/2);ans=max(ans,(long long)(n-i-b)*(i-b));
	}
	printf("%lld",ans);
}