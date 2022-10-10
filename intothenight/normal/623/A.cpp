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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>(n));
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u][v] = adj[v][u] = true;
	}
	vector<int> is_b(n);
	for(auto u = 0; u < n; ++ u){
		adj[u][u] = true;
		if(all_of(adj[u].begin(), adj[u].end(), [&](int x){ return x; })){
			is_b[u] = true;
		}
	}
	vector<int> vis = is_b;
	vector<vector<int>> rem;
	for(auto u = 0; u < n; ++ u){
		if(!vis[u]){
			vector<int> cur;
			function<void(int)> dfs = [&](int u){
				vis[u] = true;
				cur.push_back(u);
				for(auto v = 0; v < n; ++ v){
					if(adj[u][v] && !vis[v]){
						dfs(v);
					}
				}
			};
			dfs(u);
			for(auto u: cur){
				for(auto v: cur){
					if(!adj[u][v]){
						cout << "No\n";
						return 0;
					}
				}
			}
			rem.push_back(cur);
		}
	}
	if((int)rem.size() >= 3){
		cout << "No\n";
		return 0;
	}
	string res(n, 'b');
	if(!rem.empty()){
		for(auto u: rem.front()){
			res[u] = 'a';
		}
	}
	if((int)rem.size() >= 2){
		for(auto u: rem.back()){
			res[u] = 'c';
		}
	}
	cout << "Yes\n" << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////