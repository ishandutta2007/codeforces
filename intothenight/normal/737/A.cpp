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
	int n, k, s, t;
	cin >> n >> k >> s >> t;
	vector<array<int, 2>> a(n); // fuel, price
	for(auto i = 0; i < n; ++ i){
		for(auto j = 1; j >= 0; -- j){
			cin >> a[i][j];
		}
	}
	sort(a.rbegin(), a.rend());
	vector<int> g(k);
	for(auto i = 0; i < k; ++ i){
		cin >> g[i];
	}
	sort(g.begin(), g.end());
	vector<int> l(k + 1);
	l[0] = g[0], l[k] = s - g[k - 1];
	for(auto i = 1; i < k; ++ i){
		l[i] = g[i] - g[i - 1];
	}
	sort(l.rbegin(), l.rend());
	debug(l);
	a.erase(remove_if(a.begin(), a.end(), [&](auto p){ return p[0] < l.front(); }), a.end());
	debug(a);
	n = (int)a.size();
	int res = numeric_limits<int>::max(), i = 0;
	long long sum = 0, tot = accumulate(l.begin(), l.end(), 0LL);
	for(auto [f, p]: a){
		while(i < k + 1 && f <= 2 * l[i]){
			sum += l[i];
			++ i;
		}
		long long rem = tot - sum;
		debug(f, p, sum, rem, i);
		if(rem + (3 * sum - 1LL * f * i) <= t){
			ctmin(res, p);
		}
	}
	res != numeric_limits<int>::max() ? cout << res << "\n" : cout << "-1\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////