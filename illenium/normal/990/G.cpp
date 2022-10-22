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

int n,val[maxn];
vector <int> mp[maxn];
map <int,ll> c[maxn];
ll cnt[maxn];
map <int,ll>::iterator it1,it2;

inline void dfs(int u,int fa)
{
	c[u][val[u]]++;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(v==fa) continue;
		dfs(v,u);
		for(it1=c[u].begin();it1!=c[u].end();it1++)
			for(it2=c[v].begin();it2!=c[v].end();it2++)
				cnt[__gcd(it1->first,it2->first)]+=it1->second*it2->second;
		for(it1=c[v].begin();it1!=c[v].end();it1++)
			c[u][__gcd(val[u],it1->first)]+=it1->second;
		c[v].clear();
	}
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		val[i]=read();
		cnt[val[i]]++;
	}
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	dfs(1,0);
	for(int i=1;i<maxn;i++) if(cnt[i]) printf("%d %lld\n",i,cnt[i]);
	return 0;
}