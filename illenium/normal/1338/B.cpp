#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

int n,d[maxn],ind[maxn],V[maxn],p;
vector <int> mp[maxn];

inline void dfs(int u,int fa)
{
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i]; if(v==fa) continue;
		d[v]=d[u]+1; dfs(v,u);
	}
}

inline void dfs2(int u,int fa)
{
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i]; if(v==fa) continue;
		if(mp[v].size()==1) V[u]=1,p--;
		else dfs2(v,u);
	}
	if(V[u]) p++;
}

int main()
{
	n=read();
	rep(i,1,n-1)
	{
		int u=read(),v=read();
		mp[u].pb(v); mp[v].pb(u); ind[u]++; ind[v]++;
	}
	dfs(1,0); int mx=0,rt=0,f=0;
	rep(i,1,n) if(d[i]>mx) mx=d[i],rt=i;
	rep(i,1,n) d[i]=0; dfs(rt,0);
	rep(i,1,n) if(mp[i].size()==1&&d[i]%2==1) f=1;
	if(f==1) cout<<"3 "; else cout<<"1 ";
	
	rep(i,1,n) if(ind[i]!=1) {rt=i; break;}
	p=n; dfs2(rt,0); cout<<p-1<<endl;
	return 0;
}