#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

struct graph{
	vector<vector<int>> adj;
	vector<int> vis;
	vector<int> deg;
	vector<int> nodes[3];
	int n;
	graph(int n): n(n), adj(n), vis(n), deg(n){};
	void add_edge(int a, int b){
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++;
		deg[b]++;
		deg[a] %= 3;
		deg[b] %= 3;
	}
	vector<int> getCycle(){
		vector<int> prev(n, -1);
		vector<int> depth(n, -1);
		int p = -1, c = -1;
		function<void(int, int)> dfs = [&](int s, int P){
			vis[s] = 1;
			for(int v : adj[s]){
				if(vis[v] == 0){
					prev[v] = s;
					depth[v] = depth[s] + 1;
					dfs(v, s);
				}
				else if(vis[v] == 1 && v != P && (p == -1 || depth[c] - depth[p] > depth[s] - depth[v])){
					p = v;
					c = s;
				}
			}
			vis[s] = 2;
		};

		for(int i = 0; i < n; i++) if(!vis[i]){
			dfs(i, -1);
			if(p != -1){
				vector<int> ret = {p};
				int curr = c;
				while(curr != p){
					ret.push_back(curr);
					curr = prev[curr];
				}
				return ret;
			}
		}

		return {-1};
	}
	vector<int> solve(){
		clock_t st = clock();
		if(n == 1) return {-1};
		vector<int> ret;
		// deg 0
		for(int i = 0; i < n; i++) if(deg[i] == 0) return {i};
		graph g2(n);
		for(int i = 0; i < n; i++) if(deg[i] == 2){
			for(int j : adj[i]) if(deg[j] == 2 && j < i){
				g2.add_edge(i, j);
			}
		}
		vector<int> cyc = g2.getCycle();
		if(cyc[0] != -1 && sz(cyc) != n) return cyc;
		if(sz(cyc) == n) return {-1};
		vector<int> comp(n);
		vector<vector<int>> which(n);
		int curr = 0;
		function<void(int)> dfs = [&](int s){
			vis[s] = 1;
			comp[s] = curr;
			which[curr].push_back(s);
			for(int v : adj[s]){
				if(!vis[v]) dfs(v);
			}
		};
		for(int i = 0; i < n; i++) if(!vis[i]){
			dfs(i);
			curr++;
		}
		vector<int> prev(n, -1);

		function<int(int, int)> getPath = [&](int u, int prohibited){
			queue<int> q;
			q.push(u);
			prev[u] = u;
			while(!q.empty()){
				int node = q.front();
				q.pop();
				for(int node2 : adj[node]) if(node2 != prohibited && prev[node2] == -1){
					prev[node2] = node;
					q.push(node2);
					if(deg[node2] == 1){
						return node2;
					}
				}
			}
			return -1;
		};

		function<void(int, int, int)> getPath2 = [&](int u, int v, int prohibited){
			queue<int> q;
			q.push(u);
			prev[u] = u;
			while(!q.empty()){
				int node = q.front();
				q.pop();
				for(int node2 : adj[node]) if(node2 != prohibited && prev[node2] == -1){
					prev[node2] = node;
					q.push(node2);
					if(node2 == v) return;
				}
			}
			return;
		};

		vector< vector< vector<int> > > dp(n, vector<vector<int>>(3, vector<int>(3, 0)));
		vector<int> isNeighbour(n, 0);

		for(int i = 0; i < curr; i++){
			int node = -1;
			for(int j : which[i]){
				if(deg[j] == 1){
					if(node != -1){
						// path bw deg1 deg1 nodes
						int en = getPath(j, -1);
						ret.push_back(j);
						while(en != j){
							ret.push_back(en);
							en = prev[en];
						}
						if(sz(ret) == n) return {-1};
						return ret;
					}
					node = j;
				}
			}
			if(node != -1){
				vector<int> d1nodes;
				function<void(int, int)> dfs2 = [&](int s, int p){
					vis[s] = 1;
					if(isNeighbour[s]) d1nodes.push_back(s);
					for(int v : adj[s]) if(v != p && v != node) dfs2(v, s);
				};
				for(int j : adj[node]) isNeighbour[j] = 1;
				vector<vector<int>> leaves;
				vis.assign(n, 0);
				for(int j : which[i]) if(j != node && !vis[j]){
					d1nodes.clear();
					dfs2(j, -1);
					leaves.push_back(d1nodes);
				}
				if(sz(leaves) >= 2){
					assert(sz(leaves[0]) >= 2 && sz(leaves[1]) >= 2);
					ret.clear();
					ret.push_back(node);
					function<void(int, int)> gp = [&](int P, int Q){
						ret.push_back(P);
						while(Q != P){
							ret.push_back(Q);
							Q = prev[Q];
						}
					};
					prev.assign(n, -1);
					getPath2(leaves[0][0], leaves[0][1], node);
					gp(leaves[0][0], leaves[0][1]);
					getPath2(leaves[1][0], leaves[1][1], node);
					gp(leaves[1][0], leaves[1][1]);
					return ret;
				} else return {-1};
			}
		}
		return {-1};
	}
};

int main(){
	int t; sd(t);
	while(t--){
		int n, m; sd(n); sd(m);
		graph g(n);
		for(int i = 1; i <= m; i++){
			int u, v;
			sd(u); sd(v);
			u--; v--;
			g.add_edge(u, v);
		}
		vector<int> choose = g.solve();
		if(choose[0] == -1){
			printf("No\n");
			continue;
		}
		vector<int> rem(n, 1);
		for(int v : choose) rem[v] = 0;
		vector<int> ans;
		for(int i = 0; i < n; i++){
			if(rem[i]) ans.push_back(i);
		}
		if(sz(ans) == 0 || sz(ans) == n){
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		printf("%d\n", sz(ans));
		for(auto it : ans) printf("%d ", it+ 1);
		printf("\n");
	}
}