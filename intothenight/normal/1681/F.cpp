#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

struct rollback_disjoint_set{
	int n, _classes;
	vector<int> p;
	vector<pair<int, int>> recover;
	rollback_disjoint_set(int n): n(n), _classes(n), p(n, -1){ }
	// O(1)
	int classes() const{
		return _classes;
	}
	// O(log n)
	int root(int u){
		return p[u] < 0 ? u : root(p[u]);
	}
	// O(log n)
	bool share(int a, int b){
		return root(a) == root(b);
	}
	// O(log n)
	int size(int u){
		return -p[root(u)];
	}
	// O(log n)
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		if(p[u] > p[v]) swap(u, v);
		recover.emplace_back(v, p[v]);
		p[u] += p[v], p[v] = u;
		return true;
	}
	// O(log n)
	bool merge(int u, int v, auto act){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		if(p[u] > p[v]) swap(u, v);
		recover.emplace_back(v, p[v]);
		p[u] += p[v], p[v] = u;
		act(u, v);
		return true;
	}
	// O(1)
	int time(){
		return (int)recover.size();
	}
	// O((size(recover) - t) * log n)
	void reverse_to(int t){
		while((int)recover.size() > t){
			++ _classes;
			auto [v, s] = recover.back();
			recover.pop_back();
			p[p[v]] -= s, p[v] = s;
		}
	}
	// O((size(recover) - t) * log n)
	void reverse_to(int t, auto act){
		while((int)recover.size() > t){
			++ _classes;
			auto [v, s] = recover.back();
			recover.pop_back();
			int u = p[v];
			p[p[v]] -= s, p[v] = s;
			act(u, v);
		}
	}
	void clear(){
		_classes = n;
		fill(p.begin(), p.end(), -1);
		recover.clear();
	}
	vector<vector<int>> group_up(){
		vector<vector<int>> g(n);
		for(auto i = 0; i < n; ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
	}
};

// For a commutative data structure supporting true O(T(n)) insertion, support deletion in O(T(n) log n) offline.
template<class E>
struct query_tree{
	int n; // max query range
	vector<vector<E>> queues;
	query_tree(int n): n(n), queues(n << 1){ }
	void insert(E e, int ql, int qr){
		assert(0 <= ql && ql <= qr && qr <= n);
		auto recurse = [&](auto self, int u, int l, int r)->void{
			if(qr <= l || r <= ql) return;
			if(ql <= l && r <= qr) queues[u].push_back(e);
			else{
				int m = l + (r - l >> 1), v = u + 1, w = u + (m - l << 1);
				self(self, v, l, m), self(self, w, m, r);
			}
		};
		recurse(recurse, 0, 0, n);
	}
	// O(q log n) insert calls and O(n) answer calls
	template<class I, class T, class R, class A>
	void solve(I insert, T time, R reverse_to, A answer){
		auto dfs = [&](auto self, int u, int l, int r)->void{
			int timer = time();
			for(auto e: queues[u]) insert(e);
			if(r - l == 1) answer(l);
			else{
				int m = l + (r - l >> 1);
				self(self, u + 1, l, m), self(self, u + (m - l << 1), m, r);
			}
			reverse_to(timer);
		};
		dfs(dfs, 0, 0, n);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<vector<array<int, 2>>> edge(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v, c;
		cin >> u >> v >> c, -- u, -- v, -- c;
		edge[c].push_back({u, v});
	}
	query_tree<array<int, 2>> qt(n);
	for(auto c = 0; c < n; ++ c){
		for(auto [u, v]: edge[c]){
			qt.insert({u, v}, 0, c);
			qt.insert({u, v}, c + 1, n);
		}
	}
	rollback_disjoint_set dsu(n);
	auto insert = [&](array<int, 2> e)->void{
		dsu.merge(e[0], e[1]);
	};
	auto time = [&]()->int{
		return dsu.time();
	};
	auto reverse_to = [&](int t)->void{
		dsu.reverse_to(t);
	};
	long long res = 0;
	auto answer = [&](int c)->void{
		for(auto [u, v]: edge[c]){
			res += 1LL * dsu.size(u) * dsu.size(v);
		}
	};
	qt.solve(insert, time, reverse_to, answer);
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////