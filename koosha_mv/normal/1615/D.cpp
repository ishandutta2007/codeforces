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

const int N=3e5+99;

int n,m,t,mv,dist[N],mark[N];
vector<pair<int,int> > g[N],G[N];
vector<pair<int,pair<int,int> > > ans;

void dfs(int u){
	//cout<<u<<" : "<<dist[u]<<endl;
	mark[u]=1;
	for(auto p : G[u]){
		int v=p.F,w=p.S;
		if(mark[v]){
			if(dist[v]!=dist[u]^w){
				mv=1;
			}
		}
		else{
			dist[v]=dist[u]^w;
			dfs(v);
		}
	}
}
void dfs1(int u,int p){
	for(auto v : g[u]){
		if(v.F==p) continue ;
		if(v.S!=-1) ans.pb({v.S,{u,v.F}});
		else ans.pb({dist[u]^dist[v.F],{u,v.F}});
		dfs1(v.F,u);
	}
}
void Main(){
	cin>>n>>m;
	f(i,1,n+1) g[i].clear(),G[i].clear(),mark[i]=0; ans.clear();
	f(i,1,n){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb(mp(v,w));
		g[v].pb(mp(u,w));
		if(w==-1) continue;
		G[u].pb(mp(v,nb(w)&1));
		G[v].pb(mp(u,nb(w)&1));
	}
	f(i,0,m){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].pb(mp(v,nb(w)&1));
		G[v].pb(mp(u,nb(w)&1));
	}
	mv=0;
	f(i,1,n+1){
		if(!mark[i]){
			dfs(i);
		}
	}
	if(mv==1){
		cout<<"NO"<<endl;
		return ;
	}
	cout<<"YES"<<endl;
	dfs1(1,0);
	f(i,0,ans.size()){
		cout<<ans[i].S.F<<" "<<ans[i].S.S<<" "<<ans[i].F<<'\n';
	}
}

main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//t=1;
	cin>>t;
	while(t--){
		Main();
	}	
}