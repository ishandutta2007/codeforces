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
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<typename Head, typename... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "----DEBUG BEGIN----\n[" << #__VA_ARGS__ << "]:", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(auto &s: a){
		cin >> s;
	}
	vector<vector<int>> calc(n, vector<int>(m, 1)); // number of consecutive bottom left
	for(auto i = n - 2; i >= 0; -- i){
		for(auto j = 1; j < m; ++ j){
			if(a[i][j] == a[i + 1][j - 1]){
				calc[i][j] = calc[i + 1][j - 1] + 1;
			}
		}
	}
	vector<vector<int>> dp(n, vector<int>(m, 1));
	for(auto i = 1; i < n; ++ i){
		for(auto j = 1; j < m; ++ j){
			if(a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1]){
				int x = max(dp[i - 1][j], dp[i][j - 1]);
				if(dp[i - 1][j] == dp[i][j - 1]){
					if(m - j >= x + 1 && a[i][j] == a[i][j + x - 1] && a[i][j] == a[i][j + x] && calc[i][j + x - 1] >= x && calc[i][j + x] >= x + 1){
						dp[i][j] = x + 1;
					}
					else if(a[i][j] == a[i][j + x - 1] && calc[i][j + x - 1] >= x){
						dp[i][j] = x;
					}
					else{
						dp[i][j] = x - 1;
					}
				}
				else if(abs(dp[i - 1][j] - dp[i][j - 1]) == 1){
					if(m - j >= x && a[i][j] == a[i][j + x - 1] && calc[i][j + x - 1] >= x){
						dp[i][j] = x;
					}
					else{
						dp[i][j] = x - 1;
					}
				}
				else{
					dp[i][j] = x - 1;
				}
			}
		}
	}
	debug2(dp);
	long long res = 0;
	for(auto x: dp){
		res += accumulate(x.begin(), x.end(), 0LL);
	}
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