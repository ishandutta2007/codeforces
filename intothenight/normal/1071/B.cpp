#include <bits/stdc++.h>
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<string> a(n);
	for(auto &s: a){
		cin >> s;
	}
	vector maxa(n, vector<int>(n));
	int len = 0;
	vector<array<int, 2>> pos;
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < n; ++ j){
			if(i){
				ctmax(maxa[i][j], maxa[i - 1][j]);
			}
			if(j){
				ctmax(maxa[i][j], maxa[i][j - 1]);
			}
			maxa[i][j] += a[i][j] == 'a';
			if(i + j + 1 <= maxa[i][j] + k){
				if(len < i + j + 1){
					len = i + j + 1;
					pos = {{i, j}};
				}
				else if(len == i + j + 1){
					pos.push_back({i, j});
				}
			}
		}
	}
	debug(len);
	if(!len){
		pos.push_back({0, 0});
	}
	debug(pos);
	vector<array<int, 2>> dr{{1, 0}, {0, 1}};
	vector prev(n, vector(n, pair{-1, -1}));
	for(auto l = len + 1; l < 2 * n; ++ l){
		vector<array<int, 2>> pos_next;
		char minchar = 'z';
		for(auto [i, j]: pos){
			for(auto [dx, dy]: dr){
				int ni = i + dx, nj = j + dy;
				if(ni < n && nj < n){
					if(minchar > a[ni][nj]){
						minchar = a[ni][nj];
						pos_next = {{ni, nj}};
						prev[ni][nj] = {i, j};
					}
					else if(minchar == a[ni][nj]){
						pos_next.push_back({ni, nj});
						prev[ni][nj] = {i, j};
					}
				}
			}
		}
		swap(pos, pos_next);
		sort(pos.begin(), pos.end()), pos.erase(unique(pos.begin(), pos.end()), pos.end());
	}
	string res;
	for(auto rep = 0, x = n - 1, y = n - 1; rep < 2 * n - len - 1; ++ rep){
		res.push_back(a[x][y]);
		tie(x, y) = prev[x][y];
	}
	res.insert(res.end(), len, 'a');
	reverse(res.begin(), res.end());
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