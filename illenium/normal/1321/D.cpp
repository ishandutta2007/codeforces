#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
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

vector <int> mp[maxn],p[maxn];
int n,m,k,dis[maxn],vis[maxn],T[maxn],s,t,ans1,ans2;
queue <int> q;
map <int,int> p2[maxn];

int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		mp[v].push_back(u); p[u].push_back(v);
	}
	k=read();
	for(int i=1;i<=k;i++) T[i]=read(); s=T[0],t=T[k];
	q.push(t); vis[t]=1;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<mp[u].size();i++)
		{
			int v=mp[u][i];
			if(vis[v]) continue;
			vis[v]=1; q.push(v); dis[v]=dis[u]+1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<p[i].size();j++)
		{
			int v=p[i][j]; //cout<<i<<" "<<v<<" "<<dis[v]<<endl;
			if(p2[i][dis[v]]==0) p2[i][dis[v]]=1;
			else if(p2[i][dis[v]]==1) p2[i][dis[v]]=2;
		}
	}
	//cout<<p2[8][3]<<endl;
	//for(int i=1;i<=n;i++) cout<<dis[i]<<" "; cout<<endl;
	for(int i=2;i<=k;i++)
	{
		if(dis[T[i]]!=dis[T[i-1]]-1) ans1++,ans2++;
		else
		{
			if(p2[T[i-1]][dis[T[i]]]==2) ans2++;
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}