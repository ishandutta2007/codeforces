#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// kunh was faster a few times, it is shorter,
// but has an n^2 countertest iirc and could be slow when left part is larger
// bipartite matching
// sqrt(N) * M
// does bfs from unmatched nodes while alternating edges between
// unmatched, matched, ... stops when it finds and unmatched node
// (has to be on the right side). then it does dfses on the created
// graph (finds alternating paths). repeats everything.
struct HopcroftKarp{
	int n,m;
	vector<int>ma,mb,dist; // n is a dummy node
	vector<vector<int>>g;
	bool bfs(){
		dist.assign(n+1,INT_MAX);
		queue<int>q;
		for(int i=0;i<n;++i)
			if(ma[i]==-1){
				q.push(i);
				dist[i]=0;
			}
		while(q.size()){
			int u=q.front();q.pop();
			if(u==n)break;
			for(auto v:g[u])if(dist[mb[v]]==INT_MAX){
				dist[mb[v]]=dist[u]+1;
				q.push(mb[v]);
			}
		}
		return dist[n]!=INT_MAX;
	}
	bool dfs(int u){
		if(u==n)return true;
		for(auto v:g[u])if(dist[mb[v]]==dist[u]+1&&dfs(mb[v])){
			mb[v]=u;
			ma[u]=v;
			return true;
		}
		dist[u]=INT_MAX;
		return false;
	}
	int maxbpm(){
		int res=0;
		while(bfs())
			for(int i=0;i<n;++i)
				res+=ma[i]==-1&&dfs(i);
		return res;
	}
	HopcroftKarp(int n,int m):n(n),m(m),ma(n,-1),mb(m,n),g(n){}
	void ae(int u,int v){g[u].push_back(v);}
};

const int N=200100;
int a[N],has[N],vis[N],nuse[N];
void dfs(int u){
	vis[u]=1;
	if(vis[a[u]]){
		vis[u]=2;
		if(vis[a[u]]==1)nuse[u]=true;
		return;
	}else dfs(a[u]);
	vis[u]=2;
}

void ProGamerMove(){
	int n;cin>>n;
	memset(has,0,sizeof(*has)*n);
	memset(vis,0,sizeof(*vis)*n);
	memset(nuse,0,sizeof(*nuse)*n);
	for(int i=0;i<n;++i)cin>>a[i],has[--a[i]]=true;
	for(int i=0;i<n;++i)if(!has[i])dfs(i);
	HopcroftKarp hk(n,n);
	for(int i=0;i<n;++i){
		if(!nuse[i])hk.ae(i,a[i]);
	}
	int k=hk.maxbpm();
	vector<int>res(hk.ma);
	vector<pair<int,int>>paths;
	for(int i=0;i<n;++i)if(hk.mb[i]>=n||hk.mb[i]<0){
		int u=i;
		for(;;u=res[u]){
			if(res[u]==-1){
				paths.push_back({i,u});
				break;
			}
		}
	}
	for(int i=0;i+1<paths.size();++i)res[paths[i].second]=paths[i+1].first;
	if(paths.size())res[paths.back().second]=paths[0].first;
	cout<<k<<"\n";
	for(int i=0;i<n;++i)cout<<res[i]+1<<" ";cout<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}