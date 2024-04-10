#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,q;
int a[M],vis[M];
vector<pii>g[M];
int main(){
	cin>>n>>q;
	for(int i=1;i<=q;++i){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].eb(v,w);
		g[v].eb(u,w);
	}
	for(int j=0;j<30;++j){
		for(int i=1;i<=n;++i)vis[i]=0;
		for(int u=1;u<=n;++u){
			bool bol=0;
			for(auto o:g[u]){
				if(!(o.se>>j&1))bol=1;
				if(o.fi==u&&o.se>>j&1){
					a[u]|=1<<j;
					vis[u]=1;
				}
			}
			if(bol){
				vis[u]=1;
				for(auto o:g[u]){
					int v=o.fi,w=o.se;
					if(w>>j&1){
						vis[v]=1;
						a[v]|=1<<j;
					}
				}
			}
		}
		for(int u=1;u<=n;++u){
			if(!vis[u]){
				for(auto o:g[u]){
					int v=o.fi;
					if(v>u){
						vis[v]=1;
						a[v]|=1<<j;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)cout<<a[i]<<" ";
	return 0;
}
/*
5 1

*/