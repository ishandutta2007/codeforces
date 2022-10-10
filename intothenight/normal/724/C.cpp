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

// Returns g=gcd(a,b), and x and y store values with ax+by=g
typedef long long ll;
ll euclid(ll a, ll b, ll &x, ll &y){
	if(b){
		ll d = euclid(b, a % b, y, x);
		return y -= a / b * x, d;
	}
	return x = 1, y = 0, a;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	long long n, m, k;
	cin >> n >> m >> k;
	long long th = lcm(n, m), a, b, g = euclid(n, m, a, b);
	long long aa = a, bb = b;
	while(a < 0){
		a += m / g, b -= n / g;
	}
	while(bb < 0){
		aa -= m / g, bb += n / g;
	}
	debug(a, b);
	debug(aa, bb);
	for(auto qi = 0; qi < k; ++ qi){
		long long x, y;
		cin >> x >> y;
		long long res = numeric_limits<long long>::max();
		debug(x, y);
		auto refresh = [&](long long x, long long y){
			if((y - x) % 2 == 0){
				long long obj = (y - x) / 2;
				if(obj % g == 0){
					long long i = obj > 0 ? obj / g * a : obj / g * aa;
					i %= m / g;
					ctmin(res, 2 * n * i + x);
					debug(2 * n * i + x);
				}
			}
		};
		refresh(x, y);
		refresh(x, 2 * m - y);
		refresh(2 * n - x, y);
		refresh(2 * n - x, 2 * m - y);
		res < th ? cout << res << "\n" : cout << "-1\n";
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