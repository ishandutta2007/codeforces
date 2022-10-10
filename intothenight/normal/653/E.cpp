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
	int n, m, k;
	cin >> n >> m >> k;
	vector<array<int, 2>> nedges(m);
	int deg0 = n - 1;
	for(auto &[u, v]: nedges){
		cin >> u >> v, -- u, -- v;
		if(u > v){
			swap(u, v);
		}
		if(!u){
			-- deg0;
		}
	}
	if(deg0 < k){
		cout << "impossible\n";
		return 0;
	}
	auto count = [&](vector<array<int, 2>> nedges){
		vector<vector<int>> nadj(n);
		for(auto [u, v]: nedges){
			nadj[u].push_back(v), nadj[v].push_back(u);
		}
		const int th = 600; // size limit on the smaller component
		vector<int> c, isc(n), index(n, -1);
		for(auto u = 0; u < n; ++ u){
			if((int)nadj[u].size() >= n - th){
				isc[u] = true;
				index[u] = (int)c.size();
				c.push_back(u);
			}
		}
		vector<bitset<300000>> adj((int)c.size());
		for(auto i = 0; i < (int)c.size(); ++ i){
			adj[i].set();
			adj[i][c[i]] = false;
			for(auto v: nadj[c[i]]){
				adj[i][v] = false;
			}
		}
		vector<int> vis(n);
		int tot = !!(n - (int)c.size());
		for(auto i = 0; i < (int)c.size(); ++ i){
			if(!vis[c[i]]){
				bool isolated = true;
				int cnt = 0;
				function<void(int)> dfs = [&](int i){
					vis[c[i]] = true;
					++ cnt;
					for(auto v = 0; v < n; ++ v){
						if(!vis[v] && adj[i][v]){
							if(!isc[v]){
								isolated = false;
							}
							else{
								dfs(index[v]);
							}
						}
					}
				};
				dfs(i);
				if(cnt == n){
					return 1;
				}
				if(isolated){
					++ tot;
				}
			}
		}
		return tot;
	};
	debug(count(nedges));
	if(count(nedges) != 1){
		cout << "impossible\n";
		return 0;
	}
	// We may now assume the graph is connected. Now check degree of 1
	for(auto u = 1; u < n; ++ u){
		nedges.push_back({0, u});
	}
	sort(nedges.begin(), nedges.end()), nedges.erase(unique(nedges.begin(), nedges.end()), nedges.end());
	debug(count(nedges));
	count(nedges) <= k + 1 ? cout << "possible\n" : cout << "impossible\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////