#include <bits/stdc++.h>
using namespace std;

struct disjoint_set{
	int n;
	vector<int> p;
	disjoint_set(int n): n(n), p(n, -1){ }
	// Amortized O(alpha(n))
	int root(int u){
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
	// Amortized O(alpha(n))
	bool share(int a, int b){
		return root(a) == root(b);
	}
	// Amortized O(alpha(n))
	int size(int u){
		return -p[root(u)];
	}
	// Amortized O(alpha(n))
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
	// Amortized O(alpha(n))
	bool merge(int u, int v, auto act){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		act(u, v);
		return true;
	}
	// O(n)
	void clear(){
		fill(p.begin(), p.end(), -1);
	}
	// O(n)
	vector<vector<int>> group_up(){
		vector<vector<int>> g(n);
		for(auto i = 0; i < n; ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
	}
};

// B must be equal or greater than 2
// Partition the sorted elements according to capacity, and track the sum of each blocks
template<class T, class U, class Compare = less<>, class Plus = plus<>, class Minus = minus<>>
struct block_sum_processor{
	int B;
	Plus op;
	Minus inv_op;
	vector<U> sum;
	vector<multiset<T, Compare>> data;
	vector<int> capacity;
	block_sum_processor(int B = 2, U init = {}, Compare cmp = less<>(), Plus op = plus<>(), Minus inv_op = minus<>()): B(B), sum(B, init), data(B, multiset<T, Compare>{cmp}), capacity(B - 1), op(op), inv_op(inv_op){ }
	// O(B log n)
	void insert(T x){
		sum[0] = op(sum[0], x);
		data[0].insert(x);
		for(auto i = 0; i < B - 1 && (int)data[i].size() > capacity[i]; ++ i){
			sum[i + 1] = op(sum[i + 1], *data[i].rbegin());
			data[i + 1].insert(data[i + 1].begin(), *data[i].rbegin());
			sum[i] = inv_op(sum[i], *data[i].rbegin());
			data[i].erase(prev(data[i].end()));
		}
	}
	// O(B log n)
	void erase(T x){
		int i = 0;
		while(i < B && data[i].find(x) == data[i].end()) ++ i;
		assert(i < B);
		data[i].erase(data[i].find(x));
		sum[i] = inv_op(sum[i], x);
		for(; i < B - 1 && (int)data[i].size() < capacity[i] && !data[i + 1].empty(); ++ i){
			sum[i] = op(sum[i], *data[i + 1].begin());
			data[i].insert(data[i].end(), *data[i + 1].begin());
			sum[i + 1] = inv_op(sum[i + 1], *data[i + 1].begin());
			data[i + 1].erase(data[i + 1].begin());
		}
	}
	// O(B log n)
	void increase_capacity(int i = 0){
		assert(0 <= i && i < B - 1);
		for(++ capacity[i]; i < B - 1 && (int)data[i].size() < capacity[i] && !data[i + 1].empty(); ++ i){
			sum[i] = op(sum[i], *data[i + 1].begin());
			data[i].insert(data[i].end(), *data[i + 1].begin());
			sum[i + 1] = inv_op(sum[i + 1], *data[i + 1].begin());
			data[i + 1].erase(data[i + 1].begin());
		}
	}
	// O(B log n)
	void decrease_capacity(int i = 0){
		assert(0 <= i && i < B - 1 && capacity[i]);
		for(-- capacity[i]; i < B - 1 && (int)data[i].size() > capacity[i]; ++ i){
			sum[i + 1] = op(sum[i + 1], *data[i].rbegin());
			data[i + 1].insert(data[i + 1].begin(), *data[i].rbegin());
			sum[i] = inv_op(sum[i], *data[i].rbegin());
			data[i].erase(prev(data[i].end()));
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, d;
	cin >> n >> d;
	disjoint_set dsu(n);
	block_sum_processor<int, int, greater<>> p(2, 0, greater<>());
	p.increase_capacity();
	for(auto i = 0; i < n; ++ i){
		p.insert(1);
	}
	for(auto i = 0; i < d; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		if(dsu.share(u, v)){
			p.increase_capacity();
		}
		else{
			p.erase(dsu.size(u));
			p.erase(dsu.size(v));
			dsu.merge(u, v);
			p.insert(dsu.size(u));
		}
		cout << p.sum[0] - 1 << "\n";
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