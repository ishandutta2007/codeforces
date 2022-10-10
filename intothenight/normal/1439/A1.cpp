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
	vector<int> c{7, 11, 13, 14};
	vector<vector<array<int, 2>>> d{
		{{0, 0}, {0, 1}, {1, 0}}
		, {{0, 0}, {0, 1}, {1, 1}}
		, {{0, 0}, {1, 0}, {1, 1}}
		, {{0, 1}, {1, 0}, {1, 1}}
	};
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for(auto i = 0; i < n; ++ i){
			string s;
			cin >> s;
			for(auto j = 0; j < m; ++ j){
				a[i][j] = s[j] - '0';
			}
		}
		vector<vector<int>> res;
		auto insert = [&](int x, int y, int mask){
			for(auto cmask = 0; cmask < 16; ++ cmask){
				int cur = 0;
				for(auto i = 0; i < 4; ++ i){
					if(cmask & 1 << i){
						cur ^= c[i];
					}
				}
				if(cur == mask){
					for(auto i = 0; i < 4; ++ i){
						if(cmask & 1 << i){
							res.emplace_back();
							for(auto [dx, dy]: d[i]){
								res.back().push_back(x + dx);
								res.back().push_back(y + dy);
							}
						}
					}
					debug(cur, mask);
					break;
				}
			}
			for(auto i = 0; i < 2; ++ i){
				for(auto j = 0; j < 2; ++ j){
					a[x + i][y + j] = 0;
				}
			}
		};
		for(auto i = 1; i < n; i += 2){
			for(auto j = 1; j < m; j += 2){
				int mask = 0;
				for(auto ii = 0; ii < 2; ++ ii){
					for(auto jj = 0; jj < 2; ++ jj){
						mask |= a[i - 1 + ii][j - 1 + jj] << ii * 2 + jj;
					}
				}
				insert(i - 1, j - 1, mask);
			}
		}
		for(auto i = 1; i < n; i += 2){
			int mask = 0;
			for(auto ii = 0; ii < 2; ++ ii){
				for(auto jj = 0; jj < 2; ++ jj){
					mask |= a[i - 1 + ii][m - 2 + jj] << ii * 2 + jj;
				}
			}
			insert(i - 1, m - 2, mask);
		}
		for(auto j = 1; j < m; j += 2){
			int mask = 0;
			for(auto ii = 0; ii < 2; ++ ii){
				for(auto jj = 0; jj < 2; ++ jj){
					mask |= a[n - 2 + ii][j - 1 + jj] << ii * 2 + jj;
				}
			}
			insert(n - 2, j - 1, mask);
		}
		if(a[n - 1][m - 1]){
			insert(n - 2, m - 2, 8);
		}
		cout << (int)res.size() << "\n";
		for(auto p: res){
			for(auto i = 0; i < 6; ++ i){
				cout << p[i] + 1 << " ";
			}
			cout << "\n";
		}
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