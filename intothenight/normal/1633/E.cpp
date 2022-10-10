#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<bool Enable_small_to_large = true>
struct disjoint_set{
	int n, _classes;
	vector<int> p;
	disjoint_set(int n): n(n), _classes(n), p(n, -1){ }
	int classes() const{
		return _classes;
	}
	int root(int u){
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
	bool share(int a, int b){
		return root(a) == root(b);
	}
	int size(int u){
		return -p[root(u)];
	}
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		if constexpr(Enable_small_to_large) if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
	bool merge(int u, int v, auto act){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		if constexpr(Enable_small_to_large) if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		act(u, v);
		return true;
	}
	void clear(){
		_classes = n;
		fill(p.begin(), p.end(), -1);
	}
	vector<vector<int>> group_up(){
		vector<vector<int>> g(n);
		for(auto i = 0; i < n; ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<array<int, 3>> edge(m);
	for(auto &[w, u, v]: edge){
		cin >> u >> v >> w, -- u, -- v;
	}
	ranges::sort(edge);
	vector<int> pivot;
	for(auto i = 0; i < m; ++ i){
		pivot.push_back(edge[i][0]);
		for(auto j = i + 1; j < m; ++ j){
			pivot.push_back(edge[i][0] + edge[j][0] >> 1);
		}
	}
	pivot.push_back(100000000);
	ranges::sort(pivot);
	pivot.erase(unique(pivot.begin(), pivot.end()), pivot.end());
	int k = (int)pivot.size();
	vector<long long> c0(k), c1(k);
	disjoint_set dsu(n);
	for(auto i = 0; i < k; ++ i){
		dsu.clear();
		int w = pivot[i], l = -1, r;
		while(l + 1 < m && edge[l + 1][0] < w){
			++ l;
		}
		r = l + 1;
		while(dsu.classes() >= 2){
			if(l >= 0 && (r == m || w - edge[l][0] <= edge[r][0] - w)){
				if(dsu.merge(edge[l][1], edge[l][2])){
					c0[i] -= edge[l][0];
					++ c1[i];
				}
				-- l;
			}
			else{
				if(dsu.merge(edge[r][1], edge[r][2])){
					c0[i] += edge[r][0];
					-- c1[i];
				}
				++ r;
			}
		}
	}
	auto solve = [&](int w)->long long{
		int i = ranges::lower_bound(pivot, w) - pivot.begin();
		return c0[i] + c1[i] * w;
	};
	long long xor_res = 0;
	int qn0, qn, A, B, C, last = 0;
	cin >> qn0 >> qn >> A >> B >> C;
	for(auto qi = 0; qi < qn0; ++ qi){
		int w;
		cin >> w;
		xor_res ^= solve(w);
		last = w;
	}
	for(auto qi = qn0; qi < qn; ++ qi){
		last = (1LL * last * A + B) % C;
		xor_res ^= solve(last);
	}
	cout << xor_res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////