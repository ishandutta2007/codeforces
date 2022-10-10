#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

// DEBUG BEGIN
template<typename L, typename R>
ostream &operator<<(ostream &out, pair<L, R> p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<typename Tuple, size_t ...Is>
void print_tuple(ostream &out, Tuple t, index_sequence<Is...>){
	((out << (Is ? ", " : "") << get<Is>(t)), ...);
}
template<typename ...Args>
ostream &operator<<(ostream &out, tuple<Args...> t){
	out << "(", print_tuple(out, t, index_sequence_for<Args...>{}); return out << ")";
}
template<typename ...Args, template<typename...> typename T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, T<Args...> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<typename T, size_t N>
ostream &operator<<(ostream &out, array<T, N> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S>
ostream &operator<<(ostream &out, bitset<S> b){
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
	int n;
	cin >> n;
	vector<int> a(n), psum(n + 1), cnt1(n + 1), cnt2(n + 1);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		psum[i + 1] = psum[i] + a[i];
		cnt1[i + 1] = cnt1[i] + (a[i] == 1000);
		cnt2[i + 1] = cnt2[i] + (a[i] == 2000);
	}
	auto sum = [&](int i, int j){
		return psum[j] - psum[i];
	};
	int res = numeric_limits<int>::max() / 2;
	for(auto i = 1; i <= n; ++ i){ // full-paying first i
		ctmin(res, psum[i] + max(0, sum(i, n) - psum[i] / 10));
		debug(i, res);
		if(i <= n - 2){
			if(a[i] == 2000){
				static int j = 0;
				while(j < n && (j < i || a[j] == 2000)){
					++ j;
				}
				if(j != n){
					int bal = max(0, psum[i] / 10 - sum(i, j)) + a[j] / 10;
					ctmin(res, psum[i] + max(0, sum(i, j) - psum[i] / 10) + a[j] + max(0, sum(j + 1, n) - bal));
					debug("C1", res, j);
				}
			}
			else if(a[i + 1] == 2000){
				for(auto j = i + 2; ; ++ j){
					int bal = max(0, psum[i] / 10 - a[i]) + sum(i + 1, j) / 10;
					ctmin(res, psum[i] + max(0, a[i] - psum[i] / 10) + sum(i + 1, j) + max(0, sum(j, n) - bal));
					debug("C2", res, j);
					if(j == n || a[j] == 1000){
						break;
					}
				}
			}
		}
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