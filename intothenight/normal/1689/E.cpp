#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }

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
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		int res = 0;
		for(auto i = 0; i < n; ++ i){
			if(!a[i]){
				++ a[i];
				++ res;
			}
		}
		auto check = [&]()->bool{
			array<int, 30> cnt{};
			disjoint_set dsu(30);
			for(auto i = 0; i < n; ++ i){
				int bbit = __builtin_ctz(a[i]);
				for(auto bit = bbit; bit < 30; ++ bit){
					if(a[i] & 1 << bit){
						++ cnt[bit];
						dsu.merge(bbit, bit);
					}
				}
			}
			int c = 0;
			for(auto g: dsu.group_up()){
				if(cnt[g.front()]){
					++ c;
				}
			}
			return c <= 1;
		};
		if(check()){
			cout << res << "\n";
			ranges::copy(a, ostream_iterator<int>(cout, " "));
			cout << "\n";
			return 0;
		}
		for(auto i = 0; i < n; ++ i){
			++ a[i];
			++ res;
			if(check()){
				cout << res << "\n";
				ranges::copy(a, ostream_iterator<int>(cout, " "));
				cout << "\n";
				return 0;
			}
			-- a[i];
			-- res;
			if(a[i] >= 2){
				-- a[i];
				++ res;
				if(check()){
					cout << res << "\n";
					ranges::copy(a, ostream_iterator<int>(cout, " "));
					cout << "\n";
					return 0;
				}
				++ a[i];
				-- res;
			}
		}
		int mxbase = 0;
		for(auto x: a){
			ctmax(mxbase, __builtin_ctz(x));
		}
		int i = 0;
		while(i < n && __builtin_ctz(a[i]) != mxbase){
			++ i;
		}
		assert(i < n);
		++ res;
		-- a[i];
		++ i;
		while(i < n && __builtin_ctz(a[i]) != mxbase){
			++ i;
		}
		assert(i < n);
		++ res;
		++ a[i];
		assert(check());
		cout << res << "\n";
		ranges::copy(a, ostream_iterator<int>(cout, " "));
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