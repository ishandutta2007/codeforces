#include <bits/stdc++.h>
using namespace std;

// DEBUG BEGIN
#ifdef LOCAL
template<typename L, typename R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<typename Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<typename Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<typename... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<typename ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<typename T> ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<typename Head, typename... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "----DEBUG BEGIN----\n[" << #__VA_ARGS__ << "]:", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<array<int, 2>>> adj(n);
	for(int i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		adj[u].push_back({v, w});
	}
	vector<vector<array<int, 2>>> req(n);
	for(auto u = 0; u < n; ++ u){
		sort(adj[u].begin(), adj[u].end(), [&](auto p, auto q){ return p[1] < q[1]; });
		for(auto i = 0; i < int(adj[u].size()); ++ i){
			int v = adj[u][i][0];
			req[v].push_back({int(adj[u].size()) - 1, i});
		}
	}
	for(auto u = 0; u < n; ++ u){
		sort(req[u].begin(), req[u].end()), req[u].erase(unique(req[u].begin(), req[u].end()), req[u].end());
	}
	sort(req.begin(), req.end()), req.erase(unique(req.begin(), req.end()), req.end());
	int res = 0;
	function<void(int)> solve = [&](int i){
		static vector<int> cur(k);
		debug(i, cur);
		if(i == k){
			for(auto &a: req){
				for(auto [deg, ind]: a){
					if(cur[deg] == ind){
						goto OK;
					}
				}
				goto FAIL;
				OK:;
			}
			++ res;
			FAIL:;
			return;
		}
		solve(i + 1);
		for(auto x = 1; x <= i; ++ x){
			cur[i] = x;
			solve(i + 1);
		}
		cur[i] = 0;
	};
	solve(0);
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