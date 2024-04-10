#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// IF YOU WANT MINCUT, just run a dfs afterwards that visits everything
// and then cut edges that have 1 node visited and 1 unvisited
// creates bfs levels and spams multiple dfs that only go forward,
// each dfs finds a path and adds some flow, when you can't find more paths
// it does a new bfs and repeats
// works in O(V^2 * E), should be much faster though, probably like V^2 idk
// edges with capacity 1e9 are not an issue!
template<typename T>
struct Dinitz{
	const T inf=is_same<T,int>::value?1e9:1e18;
	int n;
	struct Edge{
		int to;
		T cap;
		Edge(int to,T cap):to(to),cap(cap){}
	};
	vector<Edge>e;
	vector<vector<int>>g;
	vector<int>cur,h;
	Dinitz(int n):n(n),g(n){}
	bool bfs(int s,int t){
		h.assign(n,-1);h[s]=0;
		queue<int>q;q.push(s);
		while(q.size()){
			int u=q.front();q.pop();
			for(int i:g[u]){
				auto [v,c]=e[i];
				if(c>0&&h[v]==-1){
					h[v]=h[u]+1;
					if(v==t)return true;
					q.push(v);
				}
			}
		}
		return false;
	}
	int dfs(int u,int t,T f){
		if(u==t)return f;
		T r=f;
		for(int&i=cur[u];i<g[u].size();++i){
			int j=g[u][i];
			auto [v,c]=e[j];
			if(c>0&&h[v]==h[u]+1){
				T fl=dfs(v,t,min(c,r));
				e[j].cap-=fl;
				e[j^1].cap+=fl;
				if(!(r-=fl))return f;
			}
		}
		return f-r;
	}
	// other == c if undirected?
	void addEdge(int u,int v,T c,T other=0){
		g[u].push_back(e.size());
		e.emplace_back(v,c);
		g[v].push_back(e.size());
		e.emplace_back(u,other);
	}
	int maxFlow(int s,int t){
		T res=0;
		while(bfs(s,t)){
			cur.assign(n,0);
			res+=dfs(s,t,inf);
		}
		return res;
	}
};

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n;cin>>n;
	vector<int>a(n),b(n);
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)cin>>b[i];
	vector<vector<pair<int,int>>>g(n+2);
	vector<int>last(101,-1);
	int res=0;
	Dinitz<int>f(n+2);
	for(int i=0;i<n;++i){
		if(b[i]>0){
			res+=b[i];
			f.addEdge(n,i,b[i]);
		}else{
			f.addEdge(i,n+1,-b[i]);
		}
		for(int j=1;j<=a[i];++j)
			if(~last[j]&&a[i]%j==0){
				f.addEdge(i,last[j],1e9);
			}
		last[a[i]]=i;
	}
	cout<<res-f.maxFlow(n,n+1)<<endl;
}