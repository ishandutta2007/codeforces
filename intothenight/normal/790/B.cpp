#include <bits/stdc++.h>
using namespace std;

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<class T> ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<class Head, class... Tail>
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
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> adj(n);
	for(auto i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<vector<array<long long, 2>>> dp(n, vector<array<long long, 2>>(k + 1)); // cnt, sum of steps
	long long res = 0;
	function<void(int, int)> dfs = [&](int u, int p){
		dp[u][k][0] = 1;
		for(auto v: adj[u]){
			if(v ^ p){
				dfs(v, u);
				debug(u, v);
				for(auto i = 1; i <= k; ++ i){
					for(auto j = 1; j <= k; ++ j){
						debug(dp[u][i], dp[v][j]);
						res += dp[u][i][1] * dp[v][j][0] + dp[u][i][0] * (dp[v][j][0] * (j == k) + dp[v][j][1]);
						if(i + j % k + 1 <= k){
							res -= dp[u][i][0] * dp[v][j][0];
						}
						debug(i, j, res);
					}
					if(i != 1){
						dp[u][i][0] += dp[v][i - 1][0];
						dp[u][i][1] += dp[v][i - 1][1];
					}
					else{
						dp[u][1][0] += dp[v][k][0];
						dp[u][1][1] += dp[v][k][0] + dp[v][k][1];
					}
				}
			}
		}
	};
	dfs(0, -1);
	debug2(dp);
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