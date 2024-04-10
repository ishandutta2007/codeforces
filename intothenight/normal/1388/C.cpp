#include "bits/stdc++.h"
using namespace std;

// DEBUG BEGIN
template<typename L, typename R> ostream &operator<<(ostream &out, pair<L, R> p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<typename... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<typename ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<typename ...Args, template<typename...> typename T> ostream &operator<<(enable_if_t<!is_same<T<Args...>, string>::value, ostream> &out, T<Args...> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<typename T, size_t N> ostream &operator<<(ostream &out, array<T, N> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, bitset<S> b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<int> a(n), h(n); // population, happiness
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		for(auto i = 0; i < n; ++ i){
			cin >> h[i];
		}
		vector<vector<int>> adj(n);
		for(auto i = 1; i < n; ++ i){
			int u, v;
			cin >> u >> v, -- u, -- v;
			adj[u].push_back(v), adj[v].push_back(u);
		}
		vector<int> sz(a), g(n), b(n);
		bool ok = true;
		function<void(int, int)> dfs_init = [&](int u, int p){
			for(auto v: adj[u]){
				if(v ^ p){
					dfs_init(v, u);
					sz[u] += sz[v];
				}
			}
			if(sz[u] + h[u] & 1 || (g[u] = sz[u] + h[u] >> 1) < 0 || (b[u] = sz[u] - h[u] >> 1) < 0){
				ok = false;
			}
		};
		dfs_init(0, 0);
		function<void(int, int)> check = [&](int u, int p){
			int sg = 0, sb = 0;
			for(auto v: adj[u]){
				if(v ^ p){
					check(v, u);
					sg += g[v], sb += b[v];
				}
			}
			if(sb < max(b[u] - a[u], 0)){
				ok = false;
			}
		};
		check(0, 0);
		ok ? cout << "YES\n" : cout << "NO\n";
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