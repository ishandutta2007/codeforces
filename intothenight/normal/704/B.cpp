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
	int n, s, e;
	cin >> n >> s >> e, -- s, -- e;
	vector<int> x(n), fromleft(n), fromright(n), toright(n), toleft(n);
	for(auto i = 0; i < n; ++ i){
		cin >> x[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> fromleft[i], fromleft[i] += x[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> fromright[i], fromright[i] -= x[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> toleft[i], toleft[i] += x[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> toright[i], toright[i] -= x[i];
	}
	const long long inf = numeric_limits<long long>::max() / 2;
	vector dp(n, array{inf, inf, inf});
	dp[0][1] = 0;
	// dp[i][j]: min time when i lines are incoming and i+j-1 lines are outgoing
	for(auto i = 0; i < n; ++ i){
		vector dp_next(n, array{inf, inf, inf});
		for(auto j = 0; j < n; ++ j){
			if(i == s){
				if(j){
					ctmin(dp_next[j - 1][1], dp[j][0] + toleft[i]);
					ctmin(dp_next[j - 1][2], dp[j][1] + toleft[i]);
				}
				ctmin(dp_next[j][1], dp[j][0] + toright[i]);
				ctmin(dp_next[j][2], dp[j][1] + toright[i]);
			}
			else if(i == e){
				ctmin(dp_next[j][0], dp[j][1] + fromleft[i]);
				ctmin(dp_next[j][1], dp[j][2] + fromleft[i]);
				if(j < n - 1){
					ctmin(dp_next[j + 1][0], dp[j][1] + fromright[i]);
					ctmin(dp_next[j + 1][1], dp[j][2] + fromright[i]);
				}
			}
			else{
				if(j){
					for(auto k = 0; k <= 2; ++ k){
						if(j + k - 1 > 0){
							ctmin(dp_next[j - 1][k], dp[j][k] + toleft[i] + fromleft[i]);
						}
					}
				}
				for(auto k = 0; k <= 2; ++ k){
					if(j){
						ctmin(dp_next[j][k], dp[j][k] + toleft[i] + fromright[i]);
					}
					if(j + k - 1 > 0){
						ctmin(dp_next[j][k], dp[j][k] + toright[i] + fromleft[i]);
					}
				}
				if(j < n - 1){
					for(auto k = 0; k <= 2; ++ k){
						ctmin(dp_next[j + 1][k], dp[j][k] + toright[i] + fromright[i]);
					}
				}
			}
		}
		swap(dp, dp_next);
		dp[0][0] = inf;
		if(i != n - 1){
			dp[0][1] = inf;
		}
		debug(toleft[i], toright[i], fromleft[i], fromright[i]);
		debug2(dp);
		debug("\n");
	}
	cout << dp[0][1] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////