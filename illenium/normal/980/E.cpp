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
#define maxn 1000005
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

vector <int> mp[maxn];
int n,k,f[maxn][20];
bool vis[maxn];

void dfs(int u,int fa)
{
	f[u][0]=fa;
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<mp[u].size();i++)
	{
		if(mp[u][i]==fa) continue;
		dfs(mp[u][i],u);
	}
}

int main()
{
	n=read(); k=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs(n,0); vis[0]=vis[n]=1;
	int p=n-k-1;
	for(int i=n-1;i>=1;i--)
	{
		if(vis[i]) continue;
		int v=i,len=0;
		for(int j=19;j>=0;j--)
		{
			if(!vis[f[v][j]])
			{
				v=f[v][j];
				len+=1<<j;
			}
		}
		len++;
		if(len<=p)
		{
			v=i;
			p-=len;
			while(1)
			{
				if(vis[v]) break;
				vis[v]=1;
				v=f[v][0];
			}
		}
	}
	for(int i=1;i<=n;i++) if(!vis[i]) printf("%d ",i);
	return 0;
}