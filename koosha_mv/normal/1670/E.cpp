#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
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
#define int ll

const int N=1e6+99;

int n,t,cnt,a[N],node[N],edge[N];
vector<pair<int,int>> g[N];

void dfs1(int u,int p,int h=1){
	for(auto v : g[u]){
		if(v.F==p) continue ;
		cnt++;
		edge[v.S]=cnt+n;
		node[v.F]=cnt;
		if(h==0) swap(node[v.F],edge[v.S]);
		dfs1(v.F,u,h^1);
	}
}
void Main(){
	int p;
	cin>>p; n=(1<<p);
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	dfs1(1,1);
	node[1]=n;
	cout<<1<<endl;
	f(i,1,n+1) cout<<node[i]<<" "; cout<<endl;
	f(i,1,n) cout<<edge[i]<<" "; cout<<endl;
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		cnt=0;
		f(i,1,n+1) g[i].clear();
	}
}