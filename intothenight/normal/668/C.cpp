#include <bits/stdc++.h>
using namespace std;

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
	cout << fixed << setprecision(15);
	int n;
	cin >> n;
	vector<long double> prefmax(n + 1), prefmin(n + 1);
	for(auto i = 0; i < n; ++ i){
		long double x;
		cin >> x;
		prefmax[i + 1] = prefmax[i] + x;
	}
	for(auto i = 0; i < n; ++ i){
		long double x;
		cin >> x;
		prefmin[i + 1] = prefmin[i] + x;
	}
	vector<long double> cp(n + 1), cq(n + 1);
	long double eps = 1e-6;
	for(auto i = 1; i < n; ++ i){
		long double a = prefmax[i], b = prefmin[i] + a;
		if(b * b - 4 * a > 0){
			cp[i] = (b + sqrtl(b * b - 4 * a)) / 2;
			cq[i] = 2 * a / (b + sqrtl(b * b - 4 * a));
		}
		else{
			debug("HERE");
			cp[i] = cq[i] = b / 2;
		}
		if(cp[i] < cp[i - 1] - eps || cq[i] < cq[i - 1] - eps){
			debug("swapped");
			swap(cp[i], cq[i]);
		}
		debug(a, b, cp[i], cq[i]);
		debug(b * b, 4 * a, sqrt(b * b - 4 * a));
		debug("\n");
		//assert(cp[i - 1] <= cp[i] && cq[i - 1] <= cq[i]);
	}
	cp[n] = cq[n] = 1;
	debug(cp);
	debug(cq);
	for(auto i = 0; i < n; ++ i){
		cout << cp[i + 1] - cp[i] << " ";
	}
	cout << "\n";
	for(auto i = 0; i < n; ++ i){
		cout << cq[i + 1] - cq[i] << " ";
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