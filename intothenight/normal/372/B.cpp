#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
template<class T> ostream &operator<<(class enable_if<!is_same<T, string>::value, ostream>::type &out, const T &arr){
	out << "{"; for(auto x: arr) out << x << ", ";
	return out << (arr.empty() ? "" : "\b\b") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(auto i = 0; i < S; ++ i) out << b[i];
	return out;
}
ostream &operator<<(ostream &out, __int128_t x){
	if(!x) return out << 0;
	if(x < 0) out << "-", x = -x;
	array<int, 5> a{};
	int block = 29, it = 0;
	while(x) a[it ++] = x & (1 << block) - 1, x >>= block;
	while(it --) out << a[it];
	return out;
}
ostream &operator<<(ostream &out, __uint128_t x){
	if(!x) return out << 0;
	array<int, 5> a{};
	int block = 29, it = 0;
	while(x) a[it ++] = x & (1 << block) - 1, x >>= block;
	while(it --) out << a[it];
	return out;
}
ostream &operator<<(ostream &out, const _Bit_reference &bit){
	return out << bool(bit);
}
template<class T, class A, class C>
ostream &operator<<(ostream &out, priority_queue<T, A, C> pq){
	vector<T> a;
	while(!pq.empty()) a.push_back(pq.top()), pq.pop();
	return out << a;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
void debug_frac_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_frac_out(Head H, Tail... T){
	for(auto d = 1; ; ++ d){
		if((H * d).value <= 1000000){
			cerr << H * d << "/" << d << ", ";
			break;
		}
		else if((-H * d).value <= 1000000){
			cerr << "-" << -H * d << "/" << d << ", ";
			break;
		}
	}
	debug_frac_out(T...);
}
enum CODE{ CCRED = 31, CCGREEN = 32, CCYELLOW = 33, CCBLUE = 34, CCDEFAULT = 39 };
#define debug(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCYELLOW) << "m", debug_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug2(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "] \033[" << (int)CODE(CCYELLOW) << "m", debug2_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug_frac(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCYELLOW) << "m", debug_frac_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#else
#define debug(...) 42
#define debug2(...) 42
#define debug_frac(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, qn;
	cin >> n >> m >> qn;
	vector<string> a(n);
	vector<vector<int>> cnt(n, vector<int>(m + 1));
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		for(auto j = 0; j < m; ++ j){
			cnt[i][j + 1] = cnt[i][j] + (a[i][j] & 1);
		}
	}
	debug2(cnt);
	vector dp(n + 1, vector(m + 1, vector(m + 1, 0)));
	vector pref(n + 1, vector(m + 1, vector(m + 1, 0)));
	for(auto i = 0; i < n; ++ i){
		for(auto jl = 0; jl <= m; ++ jl){
			for(auto jr = jl + 1; jr <= m; ++ jr){
				if(cnt[i][jl] != cnt[i][jr]){
					break;
				}
				pref[i + 1][jl][jr] = dp[i + 1][jl][jr] = 1 + dp[i][jl][jr];
			}
		}
		debug(i);
		debug2(dp[i + 1]);
	}
	for(auto i = 0; i < n; ++ i){
		for(auto jl = 0; jl <= m; ++ jl){
			for(auto jr = jl; jr <= m; ++ jr){
				pref[i + 1][jl][jr] += pref[i][jl][jr];
			}
		}
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry, -- lx, -- ly;
		vector<int> h(ry - ly);
		for(auto j = ly; j < ry; ++ j){
			while(h[j - ly] < rx - lx && ~a[lx + h[j - ly]][j] & 1){
				++ h[j - ly];
			}
		}
		debug(h);
		int res = 0;
		for(auto jl = ly; jl <= ry; ++ jl){
			int ch = numeric_limits<int>::max();
			for(auto jr = jl + 1; jr <= ry; ++ jr){
				ctmin(ch, h[jr - 1 - ly]);
				res += pref[rx][jl][jr] - pref[lx][jl][jr] - dp[lx][jl][jr] * ch;
				debug(jl, jr, pref[rx][jl][jr], pref[lx][jl][jr], dp[lx][jl][jr], ch, pref[rx][jl][jr] - pref[lx][jl][jr] - dp[lx][jl][jr] * ch);
			}
		}
		cout << res << "\n";
	}
	return 0;
}

/*
(2, 3) - (4, 5)
000
110
000
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////