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
template<class T> ostream &operator<<(class enable_if<!is_same<T, string>::value, ostream>::type &out, const T &arr){
	out << "{"; for(auto x: arr) out << x << ", ";
	return out << (arr.empty() ? "" : "\b\b") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(auto i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "[" << #__VA_ARGS__ << "]", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	bool swapped = false;
	auto query = [&](int h, int w, int i0, int j0, int i1, int j1){
		if(swapped){
			swap(h, w);
			swap(i0, j0);
			swap(i1, j1);
		}
		cout << "? " << h << " " << w << " " << i0 + 1 << " " << j0 + 1 << " " << i1 + 1 << " " << j1 + 1 << endl;
		bool resp;
		cin >> resp;
		return resp;
	};
	auto answer = [&](int x){
		cout << "! " << x << endl;
	};

	int res = 1;
	for(auto rep = 0; rep < 2; ++ rep, swapped = !swapped){
		vector<int> pf;
		for(auto p = 2, x = n; p <= x; ++ p){
			if(x % p == 0){
				pf.push_back(p);
				while(x % p == 0){
					x /= p;
				}
			}
		}
		debug(n, pf);
		int period = n;
		for(auto p: pf){
			if(p == 2){
				while(period % p == 0 && query(period / p, m, 0, 0, period / p, 0)){
					period /= p;
				}
			}
			else{
				while(period % p == 0 && query(p / 2 * period / p, m, 0, 0, p / 2 * period / p, 0) && query(p / 2 * period / p, m, period / p, 0, period / p + p / 2 * period / p, 0)){
					period /= p;
				}
			}
		}
		int cur = 0;
		for(auto x = period; x <= n; x += period){
			if(n % x == 0){
				++ cur;
			}
		}
		res *= cur;
		debug(n, period, cur, res);
		swap(n, m);
	}
	answer(res);
	return 0;
}

/*
4 3

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////