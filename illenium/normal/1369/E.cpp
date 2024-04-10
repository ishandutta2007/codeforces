#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,m,a[maxn],w[maxn],inq[maxn],vis[maxn],X[maxn],Y[maxn];
queue <int> q;
vector <int> ans,V[maxn];

inline void add(int x)
{
	vis[x]=1;
	for(int i=0;i<V[x].size();i++)
	{
		int v=V[x][i]; if(inq[v]) continue;
		q.push(v); inq[v]=1;
	}
}

int main()
{
	n=read(); m=read(); rep(i,1,n) a[i]=read();
	rep(i,1,m)
	{
		int x=read(),y=read(); X[i]=x; Y[i]=y;
		w[x]++; w[y]++; V[x].pb(i); V[y].pb(i);
	}
	rep(i,1,n) if(w[i]<=a[i]) add(i);
	while(!q.empty())
	{
		int u=q.front(); q.pop(); ans.pb(u);
		if(!vis[X[u]]) w[X[u]]--;
		if(!vis[Y[u]]) w[Y[u]]--;
		if(w[X[u]]<=a[X[u]]&&(!vis[X[u]])) add(X[u]);
		if(w[Y[u]]<=a[Y[u]]&&(!vis[Y[u]])) add(Y[u]);
	}
	if(ans.size()!=m) puts("DEAD");
	else
	{
		puts("ALIVE");
		for(int i=ans.size()-1;i>=0;i--) printf("%d ",ans[i]);
	}
	return 0;
}