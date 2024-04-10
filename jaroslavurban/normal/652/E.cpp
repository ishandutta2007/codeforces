#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// v has to be the other node :(
struct E{
	int u,v,w;
};

// creates a dfs tree and those edges to children that don't have a backedge that goes above me are bridges
// ng contains a bridge tree that has bridges with old labels, so you have to use par[u] when using it 
// not tested
// what about multiedges?
struct BT{
	int n,c=0;
	vector<vector<E>>g,ng,inside;
	vector<int>par,low,dpt,vis;
	vector<E>bridges;
	BT(int n):g(n),par(n),low(n),dpt(n),vis(n){}
	void ae(E e){E oe=e;swap(oe.u,oe.v);
		g[e.u].push_back(e);
		g[e.v].push_back(oe);
	}
	void dfs2(int u,int f){
		ng.resize(c+1);inside.resize(c+1);
		vis[u]=1;par[u]=c;
		for(E e:g[u])if(e.v!=f){
			if(vis[e.v]&&par[e.v]!=c){E oe=e;swap(oe.u,oe.v);
				ng[c].push_back(e);
				ng[par[e.v]].push_back(oe);
			}else if(!vis[e.v])dfs2(e.v,f);
			if(vis[e.v]==1)inside[c].push_back(e);
		}
		vis[u]=2;
	}
	int dfs(int u,int p,int d){
		low[u]=dpt[u]=d;
		for(E e:g[u])if(e.v!=p){
			if(dpt[e.v])low[u]=min(low[u],dpt[e.v]);
			else{
				int lw=dfs(e.v,u,d+1);
				low[u]=min(low[u],lw);
				if(lw>d){
					bridges.push_back(e);
					dfs2(e.v,u);++c;
				}
			}
		}
		return low[u];
	}
	void calc(){dfs(0,0,1);dfs2(0,-1);}
};


void ProGamerMove(){
	int n,m;cin>>n>>m;
	BT bt(n);
	for(int i=0;i<m;++i){
		int u,v,w;cin>>u>>v>>w;--u;--v;
		bt.ae({u,v,w});
	}
	int anfang,ziel;cin>>anfang>>ziel;--anfang;--ziel;
	bt.calc();
	auto g=bt.ng;
	auto par=bt.par;
	int res=0;
	function<int(int,int)>dfs=[&](int u,int p){
		if(u==par[ziel]){
			for(E e2:bt.inside[u])res|=e2.w;
			return 1;
		}
		for(E e:g[u]){e.v=par[e.v];
			if(e.v==p)continue;
			if(dfs(e.v,u)){
				res|=e.w;
				for(E e2:bt.inside[u])res|=e2.w;
				return 1;
			}
		}
		return 0;
	};
	assert(dfs(par[anfang],par[anfang]));
	if(res)cout<<"YES\n";
	else cout<<"NO\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	//cin>>tc;
	while(tc--)ProGamerMove();
}