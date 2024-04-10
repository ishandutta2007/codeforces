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
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	const int inf = numeric_limits<int>::max() / 2, mx = n + 1 >> 1;
	vector c(n + 1, vector(mx + 1, inf)), cn(n + 1, vector(mx + 1, inf)), nn(n + 1, vector(mx + 1, inf));
	nn[0][0] = 0;
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j <= mx; ++ j){
			if(c[i][j] < inf){
				ctmin(cn[i + 1][j], c[i][j] + max(0, a[i] - (a[i - 1] - 1)));
			}
			if(cn[i][j] < inf){
				ctmin(c[i + 1][j + 1], cn[i][j] + max(0, a[i - 1] - min(a[i] - 1, a[i - 2] - 1)) - max(0, a[i - 1] - (a[i - 2] - 1)));
				ctmin(nn[i + 1][j], cn[i][j]);
			}
			if(nn[i][j] < inf){
				ctmin(c[i + 1][j + 1], nn[i][j] + max(0, i ? a[i - 1] - (a[i] - 1) : 0));
				ctmin(nn[i + 1][j], nn[i][j]);
			}
		}
	}
	debug2(c);
	debug2(cn);
	debug2(nn);
	for(auto k = 1; k <= mx; ++ k){
		cout << min({c[n][k], cn[n][k], nn[n][k]}) << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////