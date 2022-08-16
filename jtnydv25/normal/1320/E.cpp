#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())

#ifdef LOCAL
#define cerr cout
#else
#endif

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

struct tree {
	int n;
	vector<vector<int>> adj;
	tree(int n) : n(n), adj(n) { }
	void add_edge(int s, int t) {
		adj[s].push_back(t);
		adj[t].push_back(s);
	}
	vector<int> pos, tour, depth, pos_end;
	vector<vector<int>> table;
	int argmin(int i, int j) { return depth[i] < depth[j] ? i : j; }
	void rootify(int r) {
		pos.resize(n);
		pos_end.resize(n);
		function<void (int,int,int)> dfs = [&](int u, int p, int d) {
			pos[u] = pos_end[u] = depth.size();
			tour.push_back(u);
			depth.push_back(d);
			for (int v: adj[u]) {
				if (v != p) {
					dfs(v, u, d+1);
					pos_end[u] = depth.size();
					tour.push_back(u);
					depth.push_back(d);
				}
			}
		}; dfs(r, r, 0);
		int logn = sizeof(int)*__CHAR_BIT__-1-__builtin_clz(tour.size()); // log2
		table.resize(logn+1, vector<int>(tour.size()));
		iota(all(table[0]), 0);
		for (int h = 0; h < logn; ++h) 
			for (int i = 0; i+(1<<h) < tour.size(); ++i)
				table[h+1][i] = argmin(table[h][i], table[h][i+(1<<h)]);
	}
	int lca(int u, int v) {
		int i = pos[u], j = pos[v]; if (i > j) swap(i, j);
		int h = sizeof(int)*__CHAR_BIT__-1-__builtin_clz(j-i); // = log2
		return i == j ? u : tour[argmin(table[h][i], table[h][j-(1<<h)])];
	}
	inline int getDepth(int u){
		return depth[pos[u]];
	}
	inline int dist(int u, int v){
		return getDepth(u) + getDepth(v) - 2 * getDepth(lca(u, v));
	}

	void aux_tree(vector<int> nodes, vector<vector<int> > & adj_aux, vector<int> & start_times){
		// adj_aux stores the children
		for(int x : nodes) start_times.push_back(pos[x]);
		sort(all(start_times));
		for(int i = 1; i < (int) nodes.size();  i++){
			start_times.push_back(pos[lca(tour[start_times[i]], tour[start_times[i - 1]])]);
		}
		sort(all(start_times));
		start_times.erase(unique(start_times.begin(), start_times.end()), start_times.end());
		adj_aux.resize(start_times.size());
		stack<int> st;
        // nodes now indexed according to start_times
		st.push(0);
		for(int i = 1; i < (int)start_times.size(); i++){
			while(pos_end[tour[start_times[st.top()]]] < start_times[i]){
				st.pop();
			}
			adj_aux[st.top()].push_back(i);
			adj_aux[i].push_back(st.top());
			st.push(i);
		}
	}
	inline int gceil(int a, int b){
		return (a - 1) / b + 1;
	}

	void go(){
		int k, m; sd(k); sd(m);
		vector<int> nodes(m + k);
		vector<int> s(k);
		map<int, int> orig;
		for(int i = 0; i < k; i++){
			sd(nodes[i]); sd(s[i]); nodes[i]--;
			orig[nodes[i]] = i;
		}

		for(int i = k; i < k + m; i++) sd(nodes[i]), nodes[i]--;

		vector<vector<int>> adj_aux;
		vector<int> start_times;
		aux_tree(nodes, adj_aux, start_times);
		int num = start_times.size();
		vector<int> color(num, -1);

		priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

		for(int i = 0; i < num; i++) if(orig.find(tour[start_times[i]]) != orig.end()){
			pq.push({0, {orig[tour[start_times[i]]], i}});
		}

		while(!pq.empty()){
			auto it = pq.top(); pq.pop();
			int t = it.F;
			int col = it.S.F;
			int node = it.S.S;
			if(color[node] != -1) continue;
			color[node] = col;
			for(int v : adj_aux[node]) if(color[v] == -1){
				pq.push({gceil(dist(nodes[col], tour[start_times[v]]), s[col]), {col, v}});
			}
		}
		for(int i = k; i < k + m; i++){
			int position = upper_bound(all(start_times), pos[nodes[i]] - 1) - start_times.begin();
			printf("%d ", color[position] + 1);
		}
		printf("\n");
	}
};

int main(){
	int n; sd(n); tree T(n);
	for(int i = 1; i < n; i++){
		int u, v; sd(u); sd(v); u--; v--;
		T.add_edge(u, v);
	}
	T.rootify(0);
	int q; sd(q);
	while(q--){
		T.go();
	}
}