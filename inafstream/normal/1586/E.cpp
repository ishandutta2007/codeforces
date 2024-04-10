#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m,q,i,f[300005],res,vis[300005];
int fa[300005],dep[300005];
vector<int> ans[300005];
vector<int> adj[300005];

void dfs(int x,int p)
{
	vis[x]=1;
	fa[x]=p;
	for(int i=0;i<adj[x].size();i++)
	{
		int y=adj[x][i];if(y==p||vis[y])continue;
		dep[y]=dep[x]+1;dfs(y,x);
	}
}

int dfs2(int x,int p)
{
	int s=0;
	vis[x]=1;
	for(int i=0;i<adj[x].size();i++)
	{
		int y=adj[x][i];if(y==p||vis[y])continue;
		s+=dfs2(y,x);
	}
	res+=s/2+(f[x]==0&&(s%2));
	return f[x];
}



int main()
{
	cin>>n>>m;
	rep(i,m)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	
	cin>>q;
	rep(i,q)
	{
		int x,y;
		cin>>x>>y;
		vector<int> tmp;
		while(x!=y)
		{
			if(dep[x]>dep[y])
			{
				ans[i].push_back(x);
				f[x]^=1;
				x=fa[x];
			}
			else
			{
				tmp.push_back(y);
				f[y]^=1;
				y=fa[y];
			}
		}
		ans[i].push_back(x);
		while(!tmp.empty()) ans[i].push_back(tmp.back()),tmp.pop_back();
	}
	
	rep(i,n) if(f[i])break;
	if(i>n)
	{
		puts("YES");
		rep(i,q)
		{
			printf("%d\n",ans[i].size());
			int j;rep(j,ans[i].size()) printf("%d ",ans[i][j-1]);
			puts("");
		}
		return 0;
	}
	
	memset(vis,0,sizeof(vis));
	dfs2(1,0);
	puts("NO");
	printf("%d\n",res);
	return 0;
}