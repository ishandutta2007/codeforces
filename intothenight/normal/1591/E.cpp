#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

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

struct unital_sorter{
	// n: # of items
	// m: maximum possible freq
	// order: list of items sorted by freq (tie broken arbitrarily)
	// pos[x]: position of the item x in order
	// freq[x]: frequency of the item x
	// fpos[f]: starting position of items for freqeuncy f
	int n, m;
	vector<int> order, pos, freq, fpos;
	// O(n + m)
	unital_sorter(int n, int m): n(n), m(m), order(n), pos(n), freq(n), fpos(m + 2, n){
		fpos[0] = 0;
		iota(order.begin(), order.end(), 0);
		iota(pos.begin(), pos.end(), 0);
	}
	// O(n + m)
	unital_sorter(int n, int m, const vector<int> &freq): n(n), m(m), pos(n), freq(freq), fpos(m + 2, n){
		assert((int)freq.size() == n && *max_element(freq.begin(), freq.end()) <= m);
		iota(order.begin(), order.end(), 0);
		vector<vector<int>> occur(m + 1);
		for(auto i = 0; i < n; ++ i) occur[freq[i]].push_back(i);
		for(auto f = 0; f <= m; ++ f){
			fpos[f] = (int)order.size();
			order.insert(order.end(), occur[f].begin(), occur[f].end());
			for(auto t = fpos[f]; t < (int)order.size(); ++ t) pos[order[t]] = t;
		}
	}
	// O(1)
	void insert(int x){
		assert(freq[x] + 1 <= m);
		-- fpos[++ freq[x]];
		int y = order[fpos[freq[x]]];
		swap(pos[x], pos[y]);
		swap(order[pos[x]], order[pos[y]]);
	}
	// O(1)
	void erase(int x){
		assert(freq[x]);
		int y = order[fpos[freq[x]]];
		swap(pos[x], pos[y]);
		swap(order[pos[x]], order[pos[y]]);
		++ fpos[freq[x] --];
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, qn;
		cin >> n >> qn;
		vector<int> val(n);
		for(auto u = 0; u < n; ++ u){
			cin >> val[u], -- val[u];
		}
		vector<vector<int>> adj(n);
		for(auto u = 1; u < n; ++ u){
			int p;
			cin >> p, -- p;
			adj[p].push_back(u);
		}
		vector<vector<array<int, 3>>> q(n);
		for(auto qi = 0; qi < qn; ++ qi){
			int u, l, k;
			cin >> u >> l >> k, -- u, -- k;
			q[u].push_back({qi, l, k});
		}
		unital_sorter us(n, n);
		vector<int> res(qn, -1);
		y_combinator([&](auto self, int u)->void{
			us.insert(val[u]);
			for(auto [qi, l, k]: q[u]){
				if(int p = ranges::partition_point(us.order, [&](int x){ return us.freq[x] < l; }) - begin(us.order); p + k < n){
					res[qi] = us.order[p + k] + 1;
				}
			}
			for(auto v: adj[u]){
				self(v);
			}
			us.erase(val[u]);
		})(0);
		ranges::copy(res, ostream_iterator<int>(cout, " "));
		cout << "\n";
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