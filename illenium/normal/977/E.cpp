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

int n,m,ind[maxn],ans;
vector <int> mp[maxn];
vector <int> v;
bool vis[maxn],viss[maxn];

bool dfs(int u,int fa,int step,int top)
{
	vis[u]=1;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(v==top&&step>=2) return true;
		if(v==fa||vis[v]==1||viss[v]==0) continue;
		return dfs(v,u,step+1,top);
	}
	return false;
}

int main()
{
	n=read(); m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
		ind[u]++; ind[v]++;
	}
	for(int i=1;i<=n;i++) if(ind[i]==2) viss[i]=1;
	for(int i=1;i<=n;i++)
	{
		if(viss[i]==0) continue;
		if(dfs(i,0,0,i)==true) ans++;
	}
	cout<<ans<<endl;
	return 0;
}