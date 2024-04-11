#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,m,k,ans,a[N],col[N],cnt[N],vis[N];
vector<int> vec,g[N];

void dfs(int u){
	vec.pb(u);
	vis[u]=1;
	cnt[col[u]]++;
	for(auto v : g[u]){
		if(vis[v]) continue ;
		dfs(v);
	}
}
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	f(i,1,n+1) cin>>col[i];
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	f(i,1,n+1){
		if(vis[i]) continue ;
		vec.clear();
		dfs(i);
		int res=0;
		for(auto x : vec){
			maxm(res,cnt[col[x]]);
			cnt[col[x]]--;
		}
		ans+=res;
	}
	cout<<n-ans;
}