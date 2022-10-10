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
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 2>>> adj(n);
	vector<int> col(m);
	for(int i = 0; i < m; ++ i){
		int u, v, c;
		cin >> u >> v >> c, -- u, -- v;
		adj[u].push_back({v, i}), adj[v].push_back({u, i});
		col[i] = c;
	}
	vector<int> vis(n), vis2(n), depth(n), sum(n), res(n);
	for(auto u = 0; u < n; ++ u){
		if(!vis[u]){
			int root_val = 0;
			bool init = false;
			vector<int> cur;
			function<void(int, int)> dfs = [&](int u, int pe){
				vis[u] = 1;
				cur.push_back(depth[u] & 1 ? sum[u] : -sum[u]);
				for(auto [v, e]: adj[u]){
					if(e ^ pe && vis[v] < 2){
						debug(u, v, vis[v], depth[u]);
						if(!vis[v]){
							sum[v] = col[e] - sum[u];
							depth[v] = depth[u] + 1;
							dfs(v, e);
						}
						else if(depth[u] % 2 == depth[v] % 2){ // odd cycle
							debug(u, v);
							int u_val = sum[u] + col[e] - sum[v], cur_root_val;
							if(depth[u] & 1){
								cur_root_val = 2 * sum[u] - u_val;
							}
							else{
								cur_root_val = u_val - 2 * sum[u];
							}
							if(init && cur_root_val != root_val){
								cout << "NO\n";
								exit(0);
							}
							init = true;
							root_val = cur_root_val;
						}
						else{ // even cycle
							if(sum[u] + sum[v] != col[e]){
								cout << "NO\n";
								exit(0);
							}
						}
					}
				}
				vis[u] = 2;
			};
			dfs(u, -1);
			debug(cur);
			debug(sum);
			debug(vis);
			debug(u, root_val);
			if(init){
				res[u] = root_val;
			}
			else{
				sort(cur.begin(), cur.end());
				res[u] = cur[int(cur.size()) / 2] * 2;
			}
			debug(u, res[u]);
			function<void(int)> answer = [&](int u){
				vis2[u] = true;
				for(auto [v, e]: adj[u]){
					if(!vis2[v]){
						res[v] = 2 * col[e] - res[u];
						answer(v);
					}
				}
			};
			answer(u);
		}
	}
	cout << fixed << setprecision(15) << "YES\n";
	for(auto x: res){
		cout << x / 2.0 << " ";
	}
	cout << "\n";
	return 0;
}

/*
5 5
2 1 1
4 4 1
4 2 2
4 5 2
4 3 1

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////