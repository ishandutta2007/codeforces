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

int n,t,a[N];
vector<int> g[N];

void dfs(int u,int p,int h){
	if(h==1) a[u]=-g[u].size();
	else a[u]=g[u].size();
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs(v,u,h^1);
	}
}
void Main(){
	cin>>n;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0,0);
	f(i,1,n+1) cout<<a[i]<<" ";
	cout<<'\n';
	f(i,1,n+1) g[i].clear();
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		Main();
		f(i,1,n+1) g[i].clear();
	}
}