#include<cstdio>
#include<vector>

using namespace std;

const int MOD=998244353;
int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}

vector<int> ed[200000];

int sz[200000];

void dfs(int u,int f)
{
	sz[u]=1;
	for(int i=0;i<ed[u].size();i++)
	{
		if(ed[u][i]!=f)dfs(ed[u][i],u),sz[u]+=sz[ed[u][i]];
	}
}

int ans[200000],pw2[200000];

vector<int> div[200000];

int main()
{
	pw2[0]=1;for(int i=1;i<=100000;i++)pw2[i]=add(pw2[i-1],pw2[i-1]);
	for(int i=2;i<=100000;i++)
	{
		for(int j=2;j*i<=100000;j++)div[i*j].push_back(i);
	}
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);
		for(int i=1;i<=n;i++)ed[i].clear();
		for(int i=1,x=0,y=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);ed[x].push_back(y),ed[y].push_back(x);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++)ans[i]=0;
		ans[1]=pw2[n-1];
		for(int i=2;i<n;i++)
		{
			if((n-1)%i==0)
			{
				bool fl=1;
				for(int j=1;j<=n;j++)if(sz[j]%i!=0&&(sz[j]-1)%i!=0){fl=0;break;}
				if(fl)ans[i]=1;
			}
		}
		for(int i=n;i>=2;i--)
		{
			if(ans[i])
			{
				for(int j=0;j<div[i].size();j++)ans[div[i][j]]=0;ans[1]=sub(ans[1],1);
			}
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
	}
}