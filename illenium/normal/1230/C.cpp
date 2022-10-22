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

int n,m,a[10],u[maxn],v[maxn],ans;
vector <int> mp[maxn];
struct node{int a,b;};
map <node,int> p;
inline bool operator<(node a,node b)
{
	if(a.a==b.a) return a.b<b.b;
	return a.a<b.a;
}

inline void sol()
{
	map <node,int> p;
	int tmp=0;
	for(int i=1;i<=m;i++)
	{
		if(p[(node){a[u[i]],a[v[i]]}]==1) continue;
		p[(node){a[u[i]],a[v[i]]}]=1; tmp++;
		p[(node){a[v[i]],a[u[i]]}]=1;
	}
	ans=max(ans,tmp);
}

inline void dfs1(int dep)
{
	if(dep==n+1)
	{
		sol();
		return;
	}
	for(int i=1;i<=6;i++)
	{
		a[dep]=i;
		dfs1(dep+1);
	}
}

int main()
{
	n=read(); m=read();
	for(int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read();
		mp[u[i]].push_back(v[i]);
		mp[v[i]].push_back(u[i]);
	}
	dfs1(1);
	cout<<ans<<endl;
	return 0;
}