#include <bits/stdc++.h>
#include<algorithm>
#define salamkhoobichwtori 1e17
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int mod=1e9+7,N=200009;
ll n,x,y,g1,dp1[N],p,ans[N],f1[N];
vector<int> g[N];
ll dfs1(int ver){
	ll ans=1;
	f(i,0,g[ver].size()){
		dfs1(g[ver][i]);
		ans=(ans*(dp1[g[ver][i]]+1))%mod;}
	dp1[ver]=ans;
}
void dfs2 (int v, long long up) {
	long long x = up;
	ans[v] = up * dp1[v] % mod;
	for (int i = g[v].size() - 1; i >= 0; i --) {
		ll to = g[v][i];
		f1[to] = x;
		x = x * (dp1[to] + 1ll) % mod;
	}
	x = 1;
	f(i,0,g[v].size()) {
		ll to=g[v][i];
		long long push = (x * f1[to] % mod + 1) % mod;
		dfs2 (to, push);
		x = x * (dp1[to] + 1ll) % mod;
	}
}
int main(){
	cin>>n;
	f(i,2,n+1){
		cin>>p;
		g[p].pb(i);
	}
	dfs1(1);dfs2(1,1);
	f(i,1,n+1)
		cout<<ans[i]<<" ";
}