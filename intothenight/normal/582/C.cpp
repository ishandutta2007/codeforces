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
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<int> g(n);
	for(auto i = 0; i < n; ++ i){
		g[i] = gcd(n, i);
	}
	long long res = 0;
	for(auto low = 1, d = 1; low <= n; low = d + 1){
		d = n / (n / low);
		if(d < n && n % d == 0){
			static vector<int> ok; ok.assign(2 * n, false);
			for(auto rem = 0; rem < d; ++ rem){
				int mxval = 0;
				for(auto i = rem; i < n; i += d){
					ctmax(mxval, a[i]);
				}
				for(auto i = rem; i < n; i += d){
					ok[i] = ok[i + n] = a[i] == mxval;
				}
			}
			debug(d, ok);
			for(auto i = 0; i < n; ){
				while(i < n && !ok[i]){
					++ i;
				}
				if(i == n) break;
				int j = i;
				while(j < i + n && ok[j]){
					++ j;
				}
				if(j - i == n){
					for(auto x = d; x <= min(j - i, n - 1); x += d){
						if(g[x] == d){
							res += n;
							debug(i, j, x, n);
						}
					}
				}
				else{
					for(auto x = d; x <= min(j - i, n - 1); x += d){
						if(g[x] == d){
							res += min(n, j - x + 1) - i;
							debug(i, j, x, min(n, j - x + 1) - i);
						}
					}
				}
				i = j + 1;
			}
		}
	}
	cout << res << "\n";
	return 0;
}

/*
4
8 5 2 8 

0, 1
3, 1
3, 2
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////