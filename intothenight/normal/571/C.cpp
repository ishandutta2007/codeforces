#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 2>>> appear(m);
	vector<set<array<int, 2>>> clause(n);
	for(auto i = 0; i < n; ++ i){
		int k;
		cin >> k;
		for(auto j = 0; j < k; ++ j){
			int u;
			cin >> u;
			int sign = u / abs(u);
			u = u * sign - 1;
			appear[u].push_back({i, sign});
			clause[i].insert({u, sign});
		}
	}
	auto cmp = [&](int u, int v)->bool{
		if((int)appear[u].size() != (int)appear[v].size()){
			return (int)appear[u].size() < (int)appear[v].size();
		}
		if((int)appear[u].size() <= 1){
			return u < v;
		}
		if((appear[u][0][1] == appear[u][1][1]) != (appear[v][0][1] == appear[v][1][1])){
			return appear[u][0][1] == appear[u][1][1];
		}
		return u < v;
	};
	set<int, decltype(cmp)> s(cmp);
	for(auto u = 0; u < m; ++ u){
		s.insert(u);
	}
	vector<array<int, 2>> edge(m, {-1, -1});
	vector<vector<int>> adj(n);
	string res(m, '0');
	while(!s.empty()){
		int u = *s.begin();
		s.erase(s.begin());
		if((int)appear[u].size() <= 1 || appear[u][0][1] == appear[u][1][1]){
			res[u] = '1';
			for(auto [i, sign]: appear[u]){
				if(sign < 0){
					res[u] = '0';
				}
				for(auto [v, vsign]: clause[i]){
					if(u != v){
						s.erase(v);
						appear[v].erase(find(appear[v].begin(), appear[v].end(), array{i, vsign}));
						s.insert(v);
					}
				}
				clause[i].clear();
			}
			appear[u].clear();
		}
		else{
			if(appear[u][0][1] > 0){
				swap(appear[u][0], appear[u][1]);
			}
			int i = appear[u][0][0], j = appear[u][1][0];
			adj[i].push_back(u);
			adj[j].push_back(u);
			edge[u] = {i, j};
		}
	}
	vector<int> vis(n), depth(n), pv(n, -1), pe(n, -1), on_cycle(n);
	for(auto u = 0; u < n; ++ u){
		if(vis[u] || adj[u].empty()){
			continue;
		}
		vector<int> cycle, cycle_edge, cur;
		y_combinator([&](auto self, int u)->void{
			vis[u] = true;
			cur.push_back(u);
			for(auto id: adj[u]){
				if(id == pe[u]){
					continue;
				}
				auto &e = edge[id];
				int v = u ^ e[0] ^ e[1];
				if(!vis[v]){
					depth[v] = depth[u] + 1;
					pv[v] = u;
					pe[v] = id;
					self(v);
				}
				else if(cycle.empty() && depth[v] < depth[u]){
					on_cycle[v] = true;
					cycle.push_back(v);
					cycle_edge.push_back(id);
					for(auto w = u; w != v; w = pv[w]){
						on_cycle[w] = true;
						cycle.push_back(w);
						cycle_edge.push_back(pe[w]);
					}
				}
			}
		})(u);
		if(cycle.empty()){
			cout << "NO\n";
			return 0;
		}
		for(auto t = 0; t < (int)cycle.size(); ++ t){
			int u = cycle[t], id = cycle_edge[t], v = cycle[(t + 1) % (int)cycle.size()];
			assert(u == (v ^ edge[id][0] ^ edge[id][1]));
			res[id] = '0' + (edge[id][0] == v);
		}
		for(auto u: cur){
			if(!on_cycle[u]){
				vis[u] = false;
			}
		}
		for(auto u: cycle){
			y_combinator([&](auto self, int u)->void{
				vis[u] = true;
				for(auto id: adj[u]){
					auto e = edge[id];
					int v = u ^ e[0] ^ e[1];
					if(vis[v]){
						continue;
					}
					res[id] = '0' + (edge[id][1] == v);
					self(v);
				}
			})(u);
		}
	}
	cout << "YES\n" << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////