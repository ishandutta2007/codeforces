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
	auto __solve_tc = [&](){
		int n, m;
		vector<string> board(3);
		cin >> n >> m >> board[0] >> board[1] >> board[2];
		vector<vector<int>> dp(3, vector<int>(n - 1));
		for(auto i = 0; i < 3; ++ i){
			if(board[i][0] == 's'){
				dp[i][0] = 1;
			}
		}
		for(auto j = 0; j < n - 1; ++ j){
			for(auto i = 0; i < 3; ++ i){
				if(dp[i][j]){
					if(j + 1 == n - 1){
						cout << "YES\n";
						return 0;
					}
					if(board[i][j + 1] == '.'){
						debug(i, j + 1);
						for(auto k = -1; k <= 1; ++ k){
							if(0 <= i + k && i + k < 3 && board[i + k][j + 1] == '.'){
								debug(i + k, j + 1);
								if(j + 2 == n - 1){
									cout << "YES\n";
									return 0;
								}
								if(board[i + k][j + 2] == '.'){
									debug(i + k, j + 2);
									if(j + 3 == n - 1){
										debug(i + k, j + 3);
										cout << "YES\n";
										return 0;
									}
									if(board[i + k][j + 3] == '.'){
										dp[i + k][j + 3] = 1;
									}
								}
							}
						}
					}
				}
			}
		}
		debug(dp[0]);
		debug(dp[1]);
		debug(dp[2]);
		cout << "NO\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_it = 0; __tc_it < __tc_cnt; ++ __tc_it){
		__solve_tc();
	}
	return 0;
}

/*
...AAAAA........
s.BBB......CCCCC
...s....DDDDD...
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////