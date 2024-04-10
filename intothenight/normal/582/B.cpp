#include <bits/stdc++.h>
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }


template<typename T>
struct matrix: vector<vector<T>>{
	int n, m;
	const T add_id, mul_id;
	matrix(int n, int m, const T &add_id, const T &mul_id, bool is_id = false): n(n), m(m), add_id(add_id), mul_id(mul_id){
		this->resize(n, vector<T>(m, add_id));
		if(is_id) for(int i = 0; i < min(n, m); ++ i) (*this)[i][i] = mul_id;
	}
	matrix(const vector<vector<T>> &arr, const T &add_id, const T &mul_id): n(arr.size()), m(arr[0].size()), add_id(add_id), mul_id(mul_id){
		this->resize(n, vector<T>(m, add_id));
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) (*this)[i][j] = arr[i][j];
	}
	bool operator==(const matrix &otr) const{
		if(n != otr.n || m != otr.m) return false;
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) if((*this)[i][j] != otr[i][j]) return false;
		return true;
	}
	matrix &operator=(const matrix &otr){
		n = otr.n, m = otr.m;
		this->resize(n);
		for(int i = 0; i < n; ++ i) (*this)[i] = otr[i];
		return *this;
	}
	matrix operator+(const matrix &otr) const{
		matrix res(n, m, add_id, mul_id);
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) res[i][j] = (*this)[i][j] + otr[i][j];
		return res;
	}
	matrix &operator+=(const matrix &otr){
		return *this = *this + otr;
	}
	matrix operator*(const matrix &otr) const{
		assert(m == otr.n);
		int L = otr.m;
		matrix res(n, L, add_id, mul_id);
		for(int i = 0; i < n; ++ i) for(int j = 0; j < L; ++ j) for(int k = 0; k < m; ++ k) res[i][j] = res[i][j] + (*this)[i][k] * otr[k][j];
		return res;
	}
	matrix &operator*=(const matrix &otr){
		return *this = *this * otr;
	}
	matrix operator^(long long e) const{
		assert(n == m);
		matrix res(n, n, add_id, mul_id, true), b(*this);
		for(; e; b *= b, e >>= 1) if(e & 1) res *= b;
		return res;
	}
	matrix &operator^=(const long long e){
		return *this = *this ^ e;
	}
};

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

struct mys{
	int x;
	mys operator+(const mys &otr) const{
		return {max(x, otr.x)};
	}
	mys operator*(const mys &otr) const{
		if(!~x || !~otr.x) return {-1};
		return {x + otr.x};
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	const int sz = 300;
	//const int sz = 4;
	matrix M(sz, sz, mys({-1}), mys({0}));
	for(auto low = 0; low < sz; ++ low){
		for(auto high = 0; high < low; ++ high){
			M[low][high] = {-1};
		}
		for(auto high = low; high < sz; ++ high){
			vector<int> dp;
			for(auto x: a){
				if(low <= x && x <= high){
					int i = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
					if(i == int(dp.size())){
						dp.push_back(x);
					}
					else{
						dp[i] = x;
					}
				}
			}
			M[low][high] = {int(dp.size())};
		}
	}
	M ^= t;
	int res = 0;
	for(auto i = 0; i < sz; ++ i){
		for(auto j = 0; j < sz; ++ j){
			ctmax(res, M[i][j].x);
			debug(i, j, M[i][j].x);
		}
	}
	cout << res << "\n";
	return 0;
}

/*
5 3
1 1 2 2 3 1 1 2 2 3 1 1 2 2 3
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////