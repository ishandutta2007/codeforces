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
		int n;
		long long s;
		cin >> n >> s;
		vector<vector<array<int, 2>>> adj(n);
		for(auto i = 1; i < n; ++ i){
			int u, v, w;
			cin >> u >> v >> w, -- u, -- v;
			adj[u].push_back({v, w}), adj[v].push_back({u, w});
		}
		vector<int> sz(n);
		multimap<long long, array<int, 2>, greater<>> mp; // expected decrease, val, sz
		long long tot = 0;
		function<void(int, int, int)> dfs_sz = [&](int u, int p, int pw){
			bool is_leaf = true;
			for(auto [v, w]: adj[u]){
				if(v ^ p){
					is_leaf = false;
					dfs_sz(v, u, w);
					sz[u] += sz[v];
				}
			}
			if(is_leaf){
				sz[u] = 1;
			}
			if(u ^ p){
				tot += 1LL * pw * sz[u];
				mp.insert({1LL * (pw - pw / 2) * sz[u], {{pw, sz[u]}}});
			}
		};
		dfs_sz(0, 0, 0);
		int res = 0;
		while(tot > s){
			debug(mp, tot);
			++ res;
			auto [dec, t] = *mp.begin(); mp.erase(mp.begin());
			tot -= dec;
			t[0] >>= 1;
			mp.insert({1LL * (t[0] - t[0] / 2) * t[1], t});
		}
		cout << res << "\n";
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