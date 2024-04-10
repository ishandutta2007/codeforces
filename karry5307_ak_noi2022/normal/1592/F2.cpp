#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

bool mp[600][600];

vector<int> ed[600];
int cp[600];bool vis[600];

bool fnd(int u)
{
	for(int i=0;i<ed[u].size();i++)
	{
		if(!cp[ed[u][i]]){cp[ed[u][i]]=u;return 1;}
		if(vis[ed[u][i]])continue;
		vis[ed[u][i]]=1;if(fnd(cp[ed[u][i]])){cp[ed[u][i]]=u;return 1;}
	}
	return 0;
}

int main()
{
	int n=0,m=0;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char ch='\0';scanf(" %c",&ch);if(ch=='B')mp[i][j]=1;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){mp[i][j]=mp[i][j]^mp[i][j+1]^mp[i+1][j]^mp[i+1][j+1];if(mp[i][j])sum++;}
	sum-=(int)mp[n][m];
	
	for(int i=1;i<n;i++)for(int j=1;j<m;j++)if(mp[i][m]&&mp[n][j]&&mp[i][j])ed[i].push_back(j);
	int cnt=0;
	for(int i=1;i<n;i++){memset(vis,0,sizeof(vis));if(fnd(i))cnt++;}
	int ans=sum+mp[n][m];for(int i=1;i<=cnt;i++)ans=min(ans,sum-i+((i&1)^mp[n][m]));printf("%d",ans);
}