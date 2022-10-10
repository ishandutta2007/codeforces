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
	int n;
	cin >> n;
	array<vector<pair<int, int>>, 2> a;
	for(auto i = 0; i < n; ++ i){
		int x, y;
		cin >> x >> y;
		a[x + y & 1].push_back({x + y, x - y});
	}
	long long res = 0;
	for(auto rem = 0; rem < 2; ++ rem){
		sort(a[rem].begin(), a[rem].end());
		debug(a[rem]);
		int n = (int)a[rem].size();
		vector<int> smx(n + 1, numeric_limits<int>::min()), smn(n + 1, numeric_limits<int>::max());
		for(auto i = n - 1; i >= 0; -- i){
			smx[i] = max(smx[i + 1], a[rem][i].second);
			smn[i] = min(smn[i + 1], a[rem][i].second);
		}
		int pmx = numeric_limits<int>::min(), pmn = numeric_limits<int>::max();
		for(auto i = 0; i < n - 1; ++ i){
			pmx = max(pmx, a[rem][i].second);
			pmn = min(pmn, a[rem][i].second);
			debug(i, pmx, pmn, smx[i + 1], smn[i + 1]);
			if(a[rem][i].first != a[rem][i + 1].first && max(pmn, smn[i + 1]) < min(pmx, smx[i + 1])){
				res += 1LL * (a[rem][i + 1].first - a[rem][i].first + 1 >> 1) * (min(pmx, smx[i + 1]) - max(pmn, smn[i + 1]) + 1 >> 1);
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