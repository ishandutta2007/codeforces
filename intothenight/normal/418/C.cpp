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
	int n, m;
	cin >> n >> m;
	vector<int> x(n), y(m);
	if(n == 1){
		x = {1};
	}
	else if(n == 2){
		x = {3, 4};
	}
	else if(n & 1){
		fill(x.begin(), x.end(), 2);
		x[n - 1] = n - 2;
	}
	else{
		fill(x.begin(), x.end(), 1);
		x[n - 1] = (n - 2) / 2;
	}
	if(m == 1){
		y = {1};
	}
	else if(m == 2){
		y = {3, 4};
	}
	else if(m & 1){
		fill(y.begin(), y.end(), 2);
		y[m - 1] = m - 2;
	}
	else{
		fill(y.begin(), y.end(), 1);
		y[m - 1] = (m - 2) / 2;
	}
	debug(x);
	debug(y);
	vector<vector<int>> res(n, vector<int>(m));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			res[i][j] = x[i] * y[j];
		}
	}
	vector<long long> rsum(n), csum(m);
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			cout << res[i][j] << " ";
			rsum[i] += 1LL * res[i][j] * res[i][j];
			csum[j] += 1LL * res[i][j] * res[i][j];
		}
		cout << "\n";
	}
	for(auto i = 0; i < n; ++ i){
		long long x = sqrt(rsum[i] - 1);
		while((x + 1) * (x + 1) <= rsum[i]){
			++ x;
		}
		assert(x * x == rsum[i]);
	}
	for(auto i = 0; i < m; ++ i){
		long long x = sqrt(csum[i] - 1);
		while((x + 1) * (x + 1) <= csum[i]){
			++ x;
		}
		assert(x * x == csum[i]);
	}
	return 0;
}

/*
2mn, m^2-n^2, m^2+n^2
m>n
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////