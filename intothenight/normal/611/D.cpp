#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
T modexp(T b, long long e){
	T res = 1;
	for(; e; b *= b, e >>= 1) if(e & 1) res *= b;
	return res;
}
template<typename T>
T modinv(T a, T m){
	T u = 0, v = 1;
	while(a){
		T t = m / a;
		m -= t * a; swap(a, m);
		u -= t * v; swap(u, v);
	}
	assert(m == 1);
	return u;
}
template<typename T>
struct Z_p{
	using Type = typename decay<decltype(T::value)>::type;
	constexpr Z_p(): value(){ }
	template<typename U> Z_p(const U &x){ value = normalize(x); }
	template<typename U> static Type normalize(const U &x){
		Type v;
		if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
		else v = static_cast<Type>(x % mod());
		if(v < 0) v += mod();
		return v;
	}
	const Type& operator()() const{ return value; }
	template<typename U> explicit operator U() const{ return static_cast<U>(value); }
	constexpr static Type mod(){ return T::value; }
	Z_p &operator+=(const Z_p &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
	Z_p &operator-=(const Z_p &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
	template<typename U> Z_p &operator+=(const U &otr){ return *this += Z_p(otr); }
	template<typename U> Z_p &operator-=(const U &otr){ return *this -= Z_p(otr); }
	Z_p &operator++(){ return *this += 1; }
	Z_p &operator--(){ return *this -= 1; }
	Z_p operator++(int){ Z_p result(*this); *this += 1; return result; }
	Z_p operator--(int){ Z_p result(*this); *this -= 1; return result; }
	Z_p operator-() const{ return Z_p(-value); }
	template<typename U = T>
	typename enable_if<is_same<typename Z_p<U>::Type, int>::value, Z_p>::type& operator*=(const Z_p& rhs){
		#ifdef _WIN32
		uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
		uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
		asm(
			"divl %4; \n\t"
			: "=a" (d), "=d" (m)
			: "d" (xh), "a" (xl), "r" (mod())
		);
		value = m;
		#else
		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
		#endif
		return *this;
	}
	template<typename U = T>
	typename enable_if<is_same<typename Z_p<U>::Type, int64_t>::value, Z_p>::type& operator*=(const Z_p &rhs){
		int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template<typename U = T>
	typename enable_if<!is_integral<typename Z_p<U>::Type>::value, Z_p>::type& operator*=(const Z_p &rhs){
		value = normalize(value * rhs.value);
		return *this;
	}
	Z_p &operator/=(const Z_p &otr){ return *this *= Z_p(modinv(otr.value, mod())); }
	template<typename U> friend const Z_p<U> &abs(const Z_p<U> &v){ return v; }
	template<typename U> friend bool operator==(const Z_p<U> &lhs, const Z_p<U> &rhs);
	template<typename U> friend bool operator<(const Z_p<U> &lhs, const Z_p<U> &rhs);
	template<typename U> friend istream &operator>>(istream &in, Z_p<U> &number);
	Type value;
};
template<typename T> bool operator==(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U> bool operator==(const Z_p<T>& lhs, U rhs){ return lhs == Z_p<T>(rhs); }
template<typename T, typename U> bool operator==(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) == rhs; }
template<typename T> bool operator!=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U> bool operator!=(const Z_p<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U> bool operator!=(U lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> Z_p<T> operator+(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U> Z_p<T> operator+(const Z_p<T> &lhs, U rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U> Z_p<T> operator+(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T> Z_p<T> operator-(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U> Z_p<T> operator-(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U> Z_p<T> operator-(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T> Z_p<T> operator*(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U> Z_p<T> operator*(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U> Z_p<T> operator*(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T> Z_p<T> operator/(const Z_p<T> &lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U> Z_p<T> operator/(const Z_p<T>& lhs, U rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U> Z_p<T> operator/(U lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, Z_p<T> &number){
	typename common_type<typename Z_p<T>::Type, int64_t>::type x;
	in >> x;
	number.value = Z_p<T>::normalize(x);
	return in;
}
template<typename T> ostream &operator<<(ostream &out, const Z_p<T> &number){ return out << number(); }
constexpr int mod = (int)1e9 + 7;
//constexpr int mod = 998244353;
using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;

template<typename T, typename BO>
struct sparse_table{
	int N;
	BO bin_op;
	T id;
	vector<vector<T>> val;
	vector<int> bit;
	template<typename IT>
	sparse_table(IT begin, IT end, BO bin_op, T id): N(distance(begin, end)), bin_op(bin_op), id(id), val(__lg(N) + 1, vector<T>(begin, end)), bit(N + 1){
		for(int i = 1; i <= N; ++ i) bit[i] = __lg(i);
		for(int i = 0; i < __lg(N); ++ i) for(int j = 0; j < N; ++ j){
			val[i + 1][j] = bin_op(val[i][j], val[i][min(N - 1, j + (1 << i))]);
		}
	}
	sparse_table(){ }
	T query(int l, int r){
		if(l >= r) return id;
		int d = bit[r - l];
		return bin_op(val[d][l], val[d][r - (1 << d)]);
	}
};
template<typename Str, int lim = 256>
struct suffix_array{
	int N;
	vector<int> p, c, l; // p[i]: starting index of i-th suffix in SA, c[i]: position of suffix of index i in SA
	sparse_table<int, function<int(int, int)>> rmq;
	suffix_array(const Str &s, typename Str::value_type delim = '$'): N(s.size()), c(N){
		p = sort_cyclic_shifts(s + delim);
		p.erase(p.begin());
		for(int i = 0; i < N; ++ i) c[p[i]] = i;
		l = get_lcp(s, p);
		rmq = sparse_table<int, function<int(int, int)>>(l.begin(), l.end(), [](int x, int y){ return min(x, y); }, numeric_limits<int>::max() / 2);
	}
	vector<int> sort_cyclic_shifts(const Str &s){
		int n = int(s.size());
		vector<int> p(n), c(n), cnt(max(lim, n));
		for(auto x: s) ++ cnt[x];
		for(int i = 1; i < lim; ++ i) cnt[i] += cnt[i - 1];
		for(int i = 0; i < n; ++ i) p[-- cnt[s[i]]] = i;
		int classes = 1;
		for(int i = 1; i < n; ++ i){
			if(s[p[i]] != s[p[i - 1]]) classes ++;
			c[p[i]] = classes - 1;
		}
		vector<int> pn(n), cn(n);
		for(int h = 0; (1 << h) < n; ++ h){
			for(int i = 0; i < n; ++ i){
				pn[i] = p[i] - (1 << h);
				if(pn[i] < 0) pn[i] += n;
			}
			fill(cnt.begin(), cnt.begin() + classes, 0);
			for(auto x: pn) ++ cnt[c[x]];
			for(int i = 1; i < classes; ++ i) cnt[i] += cnt[i - 1];
			for(int i = n - 1; i >= 0; -- i) p[-- cnt[c[pn[i]]]] = pn[i];
			cn[p[0]] = 0, classes = 1;
			for(int i = 1; i < n; ++ i){
				if(c[p[i]] != c[p[i - 1]] || c[(p[i] + (1 << h)) % n] != c[(p[i - 1] + (1 << h)) % n]){
					++ classes;
				}
				cn[p[i]] = classes - 1;
			}
			c.swap(cn);
		}
		return p;
	}
	vector<int> get_lcp(const Str &s, const vector<int> &p){
		int n = int(s.size());
		vector<int> rank(n);
		for(int i = 0; i < n; ++ i) rank[p[i]] = i;
		int k = 0;
		vector<int> l(n - 1);
		for(int i = 0; i < n; ++ i){
			if(rank[i] == n - 1){
				k = 0;
				continue;
			}
			int j = p[rank[i] + 1];
			while(i + k < n && j + k < n && s[i + k] == s[j + k]) ++ k;
			l[rank[i]] = k;
			if(k) -- k;
		}
		return l;
	}
	int lcp(int i, int j){
		return rmq.query(min(c[i], c[j]), max(c[i], c[j]));
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	string s;
	cin >> n >> s;
	suffix_array sa(s);
	vector<vector<Zp>> dp(n, vector<Zp>(n + 1));
	dp[0][0] = 1;
	for(int i = 0; i < n; ++ i){
		for(int j = i + 1; j <= n; ++ j){
			dp[i][j] += dp[i][j - 1];
			if(2 * j - i <= n && s[j] != '0'){
				if(sa.lcp(i, j) < j - i && sa.c[i] < sa.c[j]){
					dp[j][2 * j - i] += dp[i][j];
				}
				else if(2 * j - i + 1 <= n){
					dp[j][2 * j - i + 1] += dp[i][j];
				}
			}
		}
	}
	Zp res = 0;
	for(int i = 0; i < n; ++ i){
		res += dp[i][n];
	}
	cout << res;
	return 0;
}

/*
dp[i][j] # of ways to split [0, j) where last selected is [i, j)

dp[]
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////