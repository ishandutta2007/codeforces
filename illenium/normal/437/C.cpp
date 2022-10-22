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

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll ans,n,m,a[maxn];
bool vis[maxn];
vector <int> mp[maxn];
struct node{ll v,id;}w[maxn];

inline bool cmp(node x,node y)
{
	if(x.v==y.v) return x.id<y.id;
	return x.v>y.v;
}

int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;i++) w[i].v=read(),w[i].id=i,a[i]=w[i].v;
	sort(w+1,w+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		vis[w[i].id]=1;
		for(int j=0;j<mp[w[i].id].size();j++)
		{
			int v=mp[w[i].id][j];
			if(vis[v]) continue;
			ans+=a[v];
		}
	}
	cout<<ans<<endl;
	return 0;
}