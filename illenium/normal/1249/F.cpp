#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,k,w[maxn],dep[maxn],tmp[maxn];
int dp[205][205];
vector <int> mp[maxn];
bool vis[maxn];

inline void dfs(int u)
{
	vis[u]=1;
	dp[u][0]=w[u];
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(vis[v]) continue;
		dfs(v);
		memset(tmp,0,sizeof(tmp));
		for(int j=0;j<=k;j++)
			for(int l=0;l<=k;l++)
				if(j+l+1>k)
					tmp[min(j,l+1)]=max(tmp[min(j,l+1)],dp[u][j]+dp[v][l]);
		for(int j=0;j<=k;j++) dp[u][j]=tmp[j];
	}
}

int main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs(1);
	int ans=0;
	for(int i=0;i<=k;i++) ans=max(ans,dp[1][i]);
	cout<<ans<<endl;
	return 0;
}