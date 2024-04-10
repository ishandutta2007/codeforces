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
	int make_set(){
		p.push_back(-1);
		++ _classes;
		return n ++;
	}
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
		bool swapped = false;
		if constexpr(Enable_small_to_large) if(p[u] > p[v]) swap(u, v), swapped = true;
		p[u] += p[v], p[v] = u;
		act(u, v, swapped);
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
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> d(n);
		copy_n(istream_iterator<int>(cin), n, d.begin());
		disjoint_set dsu(n);
		auto query = [&](int u)->int{
			cout << "? " << u + 1 << endl;
			int v;
			cin >> v;
			assert(~v);
			-- v;
			return v;
		};
		vector<int> rem(n);
		iota(rem.begin(), rem.end(), 0);
		ranges::sort(rem, [&](int u, int v){ return d[u] > d[v]; });
		for(auto u: rem){
			while(dsu.size(u) < d[u]){
				dsu.merge(u, query(u));
			}
		}
		auto g = dsu.group_up();
		vector<int> res(n, -1);
		for(auto i = 0; i < (int)g.size(); ++ i){
			for(auto u: g[i]){
				res[u] = i + 1;
			}
		}
		cout << "! ";
		ranges::copy(res, ostream_iterator<int>(cout, " "));
		cout << endl;
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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