#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
#define pb push_back
#define vi vector <int>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

vi mp[maxn];
int n,m,ind[maxn],dp[maxn],v[maxn];

inline int dfs(int u)
{
	if(v[u]) return dp[u];
	v[u]=1;
	if(mp[u].size()<=1) return dp[u]=1;
	int tmp=0;
	for(auto v:mp[u]) if(ind[v]!=1) tmp=max(tmp,dfs(v));
	return dp[u]=tmp+1;
}

int main()
{
	n=read(); m=read();
	rep(i,1,m)
	{
		int u=read(),v=read();
		mp[u].pb(v); ind[v]++;
	}
	rep(i,1,n) if(!v[i]) dfs(i);
	int ans=0; rep(i,1,n) ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}