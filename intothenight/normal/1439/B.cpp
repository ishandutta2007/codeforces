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
	auto __solve_tc = [&](int __tc_num){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> adj(n);
		vector<int> deg(n);
		for(auto i = 0; i < m; ++ i){
			int u, v;
			cin >> u >> v, -- u, -- v;
			adj[u].push_back(v), adj[v].push_back(u);
			++ deg[u], ++ deg[v];
		}
		if(1LL * k * (k - 1) / 2 > m){
			cout << "-1\n";
			return 0;
		}
		for(auto u = 0; u < n; ++ u){
			sort(adj[u].begin(), adj[u].end());
		}
		auto is_adj = [&](int u, int v){
			return binary_search(adj[u].begin(), adj[u].end(), v);
		};
		auto cmp = [&](int u, int v){
			return pair{deg[u], u} < pair{deg[v], v};
		};
		set<int, decltype(cmp)> order(cmp);
		for(auto u = 0; u < n; ++ u){
			order.insert(u);
		}
		vector<int> ded(n);
		while(!order.empty()){
			debug(order);
			debug(deg);
			int u = *order.begin(); order.erase(order.begin());
			if(deg[u] >= k){
				cout << "1 " << n - accumulate(ded.begin(), ded.end(), 0) << "\n";
				for(auto u = 0; u < n; ++ u){
					if(!ded[u]){
						cout << u + 1 << " ";
					}
				}
				cout << "\n";
				return 0;
			}
			else if(deg[u] == k - 1){
				for(auto v: adj[u]){
					if(!ded[v]){
						for(auto w: adj[u]){
							if(!ded[w] && v < w && !is_adj(v, w)){
								goto FAIL;
							}
						}
					}
				}
				cout << "2\n";
				cout << u + 1 << " ";
				for(auto v: adj[u]){
					if(!ded[v]){
						cout << v + 1 << " ";
					}
				}
				cout << "\n";
				return 0;
				FAIL:;
			}
			ded[u] = true;
			for(auto v: adj[u]){
				if(!ded[v]){
					order.erase(v);
					-- deg[v];
					order.insert(v);
				}
			}
		}
		cout << "-1\n";
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