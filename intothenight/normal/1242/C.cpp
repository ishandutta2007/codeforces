#include <bits/stdc++.h>
using namespace std;

struct functional_graph_processor{
	int n;
	vector<vector<int>> cycles; // main cycles
	vector<int> cycle_id; // id of the cycle it belongs to, -1 if not part of one
	vector<int> cycle_pos; // position in the cycle, -1 if not part of one
	vector<int> prev; // previous vertex in the cycle, -1 if not part of one
	vector<int> size; // size of the weakly connected component of the i-th main cycle
	vector<int> root; // first reachable node in the main cycle
	vector<int> depth; // # of edges from the main cycle
	vector<vector<int>> adj; // forest of arborescences of reversed edges not on the main cycle
	functional_graph_processor(const vector<int> &next): n((int)next.size()), cycle_id(n, -1), cycle_pos(n, -1), root(n, -1), depth(n, -1), adj(n){
		vector<bool> was(n);
		for(auto u = 0; u < n; ++ u){
			if(was[u]) continue;
			int v = u;
			while(!was[v]){
				was[v] = true;
				v = next[v];
			}
			if(!~depth[v]){
				int w = v;
				vector<int> cycle;
				while(!~depth[w]){
					cycle_id[w] = (int)cycles.size();
					cycle_pos[w] = (int)cycle.size();
					cycle.push_back(w);
					root[w] = w;
					depth[w] = 0;
					w = next[w];
				}
				cycles.push_back(cycle);
				size.push_back((int)cycle.size());
			}
			auto dfs = [&](auto self, int u){
				if(~depth[u]) return;
				int v = next[u];
				self(self, v);
				root[u] = root[v];
				++ size[cycle_id[root[u]]];
				depth[u] = depth[v] + 1;
				adj[v].push_back(u);
			};
			dfs(dfs, u);
		}
	}
};

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
	int n;
	cin >> n;
	map<long long, pair<int, int>> pos;
	vector<vector<int>> a(n);
	vector<vector<bool>> used(n);
	vector<vector<int>> ind(n);
	vector<array<int, 2>> order;
	vector<long long> row_sum(n);
	long long obj = 0;
	for(auto i = 0; i < n; ++ i){
		int m;
		cin >> m;
		a[i].resize(m);
		used[i].resize(m);
		ind[i].resize(m, -1);
		for(auto j = 0; j < m; ++ j){
			cin >> a[i][j];
			pos[a[i][j]] = {i, j};
			row_sum[i] += a[i][j];
			ind[i][j] = (int)order.size();
			order.push_back({i, j});
			obj += a[i][j];
		}
	}
	if(obj % n){
		cout << "No\n";
		return 0;
	}
	obj /= n;
	vector<int> next((int)order.size());
	vector<bool> bad((int)order.size());
	for(auto t = 0; t < (int)order.size(); ++ t){
		auto [i, j] = order[t];
		long long x = obj - (row_sum[i] - a[i][j]);
		if(!pos.count(x)){
			bad[t] = true;
			next[t] = t;
		}
		else{
			auto [ni, nj] = pos[x];
			next[t] = ind[ni][nj];
		}
	}
	vector<pair<int, vector<int>>> data;
	for(auto c: functional_graph_processor(next).cycles){
		if((int)c.size() == 1 && bad[c[0]]){
			continue;
		}
		int mask = 0;
		for(auto t: c){
			auto [i, j] = order[t];
			if(mask & 1 << i){
				goto NEXT;
			}
			mask |= 1 << i;
		}
		data.push_back({mask, c});
		NEXT:;
	}
	sort(data.begin(), data.end());
	vector<bool> dp(1 << n);
	vector<int> prev(1 << n, -1);
	for(auto &[mask, c]: data){
		dp[mask] = true;
	}
	for(auto mask = 1; mask < 1 << n; ++ mask){
		if(!dp[mask]){
			for(auto smask = mask - 1 & mask; smask; smask = smask - 1 & mask){
				if(dp[smask] && dp[mask ^ smask]){
					dp[mask] = true;
					prev[mask] = smask;
					break;
				}
			}
		}
	}
	if(!dp.back()){
		cout << "No\n";
		return 0;
	}
	vector<array<int, 2>> res(n, {-1, -1});
	y_combinator([&](auto self, int mask)->void{
		if(!~prev[mask]){
			auto &c = lower_bound(data.begin(), data.end(), pair{mask, vector<int>{}})->second;
			for(auto t: c){
				auto [i, j] = order[next[t]];
				res[i] = {a[i][j], order[t][0]};
			}
			return;
		}
		self(prev[mask]);
		self(mask ^ prev[mask]);
	})((1 << n) - 1);
	cout << "Yes\n";
	for(auto [x, y]: res){
		cout << x << " " << y + 1 << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////