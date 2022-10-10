#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
	Z_p operator^(long long e) const{
		Z_p b = *this, res = 1;
		for(; e; b *= b, e >>= 1) if(e & 1) res *= b;
		return res;
	}
	Z_p &operator^=(long long e){ return *this = *this ^ e; }
	Z_p &operator/=(const Z_p &otr){
		Type a = otr.value, m = mod(), u = 0, v = 1;
		while(a){
			Type t = m / a;
			m -= t * a; swap(a, m);
			u -= t * v; swap(u, v);
		}
		assert(m == 1);
		return *this *= u;
	}
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

using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using Zp = Z_p<VarMod>;

int sz = 0;
vector<int> pf;
vector<vector<Zp>> pfp;
vector<int> inf;

struct lazy_segment{
	int n, h;

#define L pair<Zp, vector<int>>           // Lazy type
#define Q pair<Zp, vector<int>>     // Query type min, cnt
	L lop(const L &lazy, const L &x){ // r1 always contain r0
		static vector<int> res(sz);
		for(auto i = 0; i < sz; ++ i){
			res[i] = lazy.second[i] + x.second[i];
		}
		return L{lazy.first * x.first, res};
	}
	Q qop(const Q &lval, const Q &rval){ // always r0[1] == r1[0]
		Zp l = lval.first, r = rval.first;
		static vector<int> res(sz);
		for(auto i = 0; i < sz; ++ i){
			if(lval.second[i] <= rval.second[i]){
				if(r) r *= pfp[i][rval.second[i] - lval.second[i]];
				res[i] = lval.second[i];
			}
			else{
				if(l) l *= pfp[i][lval.second[i] - rval.second[i]];
				res[i] = rval.second[i];
			}
		}
		return {l + r, res};
	}
	Q aop(const Q &val, const L &x){ // r1 always contain r0
		static vector<int> res(sz);
		for(auto i = 0; i < sz; ++ i){
			res[i] = val.second[i] + x.second[i];
		}
		return Q{val.first * x.first, res};
	}
	const pair<L, Q> id{{1, vector<int>(sz)}, {0, inf}};
	Q init(const int &p){
		return id.second;
	}

	vector<L> lazy;
	vector<Q> val;
	template<typename IT>
	lazy_segment(IT begin, IT end): n(distance(begin, end)), h(__lg(n) + 1), lazy(n << 1, id.first), val(n, id.second){
		val.insert(val.end(), begin, end);
		build(0, n);
	}
	lazy_segment(int n): n(n), h(__lg(n) + 1), lazy(n << 1, id.first), val(n << 1){
		for(int i = n; i < n << 1; ++ i) val[i] = init(i - n);
		build(0, n);
	}
	void refresh(int p){
		if(p < n) val[p] = qop(val[p << 1], val[p << 1 | 1]);
		if(lazy[p] != id.first) val[p] = aop(val[p], lazy[p]);
	}
	void build(int l, int r){
		for(l += n, r += n - 1; l > 1; ){
			l >>= 1, r >>= 1;
			for(int i = r; i >= l; -- i) refresh(i);
		}
	}
	void push(int l, int r){
		int s = h;
		for(l += n, r += n - 1; s > 0; -- s){
			for(int i = l >> s; i <= r >> s; ++ i) if(lazy[i] != id.first){
				val[i << 1] = aop(val[i << 1], lazy[i]);
				lazy[i << 1] = lop(lazy[i << 1], lazy[i]);
				val[i << 1 | 1] = aop(val[i << 1 | 1], lazy[i]);
				lazy[i << 1 | 1] = lop(lazy[i << 1 | 1], lazy[i]);
				lazy[i] = id.first;
			}
		}
	}
	void update(int l, int r, L x){
		if(l >= r) return;
		push(l, l + 1), push(r - 1, r);
		bool cl = false, cr = false;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(cl) refresh(l - 1);
			if(cr) refresh(r);
			if(l & 1){
				val[l] = aop(val[l], x);
				if(l < n) lazy[l] = lop(lazy[l], x);
				++ l;
				cl = true;
			}
			if(r & 1){
				-- r;
				val[r] = aop(val[r], x);
				if(r < n) lazy[r] = lop(lazy[r], x);
				cr = true;
			}
		}
		for(-- l; r > 0; l >>= 1, r >>= 1){
			if(cl) refresh(l);
			if(cr && (!cl || l != r)) refresh(r);
		}
	}
	Q query(int l, int r){
		push(l, l + 1);
		push(r - 1, r);
		Q resl = id.second, resr = id.second;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) resl = qop(resl, val[l]), ++ l;
			if(r & 1) -- r, resr = qop(val[r], resr);
		}
		return qop(resl, resr);
	}
	void print(){
		for(int u = 0; u < 2 * n; ++ u){
			//cout << u << "-th node represent [" << range[u][0] << ", " << range[u][1] << "), val = " << val[u] << ", lazy = " << lazy[u] << "\n";
		}
	}
#undef L
#undef Q
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n >> mod;
	int t = mod;
	for(auto p = 2; p * p <= t; ++ p){
		if(t % p == 0){
			int i = int(pf.size());
			pf.push_back(p);
			pfp.push_back({1});
			pfp.back().reserve(2000000);
			for(auto j = 0; j < 2000000; ++ j){
				pfp[i].push_back(pfp[i].back() * pf[i]);
			}
			while(t % p == 0){
				t /= p;
			}
		}
	}
	if(t > 1){
		int i = int(pf.size());
		pf.push_back(t);
		pfp.push_back({1});
		pfp.back().reserve(2000000);
		for(auto j = 0; j < 2000000; ++ j){
			pfp[i].push_back(pfp[i].back() * pf[i]);
		}
	}
	sz = int(pf.size());
	inf.assign(sz, 1e9);
	vector<pair<Zp, vector<int>>> a(n);
	auto process = [&](int x){
		static vector<int> b(sz);
		fill(b.begin(), b.end(), 0);
		for(auto i = 0; i < sz; ++ i){
			while(x % pf[i] == 0){
				x /= pf[i];
				++ b[i];
			}
		}
		return pair<Zp, vector<int>>{x, b};
	};
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		a[i] = process(x);
	}
	lazy_segment tr(a.begin(), a.end());
	int qq;
	cin >> qq;
	while(qq --){
		int type;
		cin >> type;
		if(type == 1){
			int l, r, x;
			cin >> l >> r >> x, -- l;
			tr.update(l, r, process(x));
		}
		else if(type == 2){
			int p, x;
			cin >> p >> x, -- p;
			auto [a, b] = process(x);
			for(auto i = 0; i < sz; ++ i){
				b[i] = -b[i];
			}
			tr.update(p, p + 1, {1 / a, b});
		}
		else{
			int l, r;
			cin >> l >> r, -- l;
			auto [a, b] = tr.query(l, r);
			Zp res = a;
			for(auto i = 0; i < sz; ++ i){
				res *= pfp[i][b[i]];
			}
			cout << res << "\n";
		}
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