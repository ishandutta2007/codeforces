#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
	auto __solve_tc = [&](int __tc_num){
		int n, k, l0, r0, l1, r1;
		cin >> n >> k >> l0 >> r0 >> l1 >> r1;
		int len = max(r0, r1) - min(l0, l1), len0 = r0 - l0, len1 = r1 - l1;
		int overlap = max(0, min(r0, r1) - max(l0, l1));
		int dis = r0 <= l1 || r1 <= l0 ? min(abs(l1 - r0), abs(l0 - r1)) : 0;
		debug(k, len, len0, len1, overlap, dis);
		if(k <= 1LL * n * overlap){
			cout << "0\n";
		}
		else{
			k -= n * overlap;
			if(k <= len - overlap){
				cout << dis + k << "\n";
			}
			else{
				long long res = 2 * len - len0 - len1 + 2 * (k - (len - overlap));
				if(k <= 1LL * (len - overlap) * n){
					long long res2 = 0;
					while(k >= len - overlap){
						res2 += 2 * len - len0 - len1;
						k -= len - overlap;
					}
					res2 += min(k * 2, dis + k);
					cout << min(res, res2) << "\n";
				}
				else{
					long long res2 = 1LL * n * (2 * len - len0 - len1) + 2 * (k - (len - overlap) * n);
					cout << min(res, res2) << "\n";
				}
			}
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