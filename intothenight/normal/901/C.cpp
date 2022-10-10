#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename Graph, typename Process_BCC, typename Process_Bridge = function<void(int, int, int)>>
int bcc(const Graph &adj, Process_BCC f, Process_Bridge g = [](int u, int v, int e){ }){
	int n = int(adj.size());
	vector<int> num(n), st;
	int timer = 0, ncomps = 0;
	function<int(int, int)> dfs = [&](int u, int pe){
		int me = num[u] = ++ timer, top = me;
		for(auto [v, e]: adj[u]) if(e != pe){
			if(num[v]){
				top = min(top, num[v]);
				if(num[v] < me) st.push_back(e);
			}
			else{
				int si = int(st.size());
				int up = dfs(v, e);
				top = min(top, up);
				if(up == me){
					st.push_back(e);
					f(vector<int>(st.begin() + si, st.end())); // Processes edgelist
					st.resize(si);
					ncomps ++;
				}
				else if(up < me) st.push_back(e);
				else g(u, v, e);
			}
		}
		return top;
	};
	for(int u = 0; u < n; ++ u) if(!num[u]) dfs(u, -1);
	return ncomps;
}

template<typename Pred>
long long custom_binary_search(long long low, long long high, Pred p, bool is_left = true){
	assert(low < high);
	if(is_left){
		while(high - low > 1){
			long long mid = low + (high - low >> 1);
			p(mid) ? low = mid : high = mid;
		}
		return low;
	}
	else{
		while(high - low > 1){
			long long mid = low + (high - low >> 1);
			p(mid) ? high = mid : low = mid;
		}
		return high;
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	vector<pair<int, int>> edge(m);
	for(int i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		edge[i] = {u, v};
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}
	vector<pair<int, int>> cycle;
	auto f = [&](const vector<int> &comp){
		if(comp.size() > 1){
			int l = 2e9, r = -2e9;
			for(auto e: comp){
				l = min({l, edge[e].first, edge[e].second});
				r = max({r, edge[e].first, edge[e].second});
			}
			cycle.emplace_back(l, r);
		}
	};
	bcc(adj, f);
	vector<int> pos(n + 1, n);
	for(auto [l, r]: cycle){
		pos[l] = r;
	}
	for(int i = n - 1; i >= 0; -- i){
		static int p = n;
		pos[i] = ctmin(p, pos[i]);
	}
	vector<long long> SUM(n + 2);
	for(int i = 0; i <= n; ++ i){
		SUM[i + 1] = SUM[i] + pos[i];
	}
	auto sum = [&](int i, int j){
		return SUM[j] - SUM[i];
	};
	int qq;
	cin >> qq;
	while(qq --){
		int ql, qr;
		cin >> ql >> qr, -- ql;
		int p = min<int>(qr, custom_binary_search(ql - 1, n, [&](int i){ return qr <= pos[i]; }, false));
		cout << sum(ql, p) + 1LL * qr * (qr - p) - 1LL * (qr - ql) * (ql + qr - 1) / 2 << "\n";
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