#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Z_p{
	using Type = typename decay<decltype(T::value)>::type;
	static vector<Type> mod_inv; 
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
	typename enable_if<is_same<typename Z_p<U>::Type, int>::value, Z_p>::type &operator*=(const Z_p& rhs){
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
	typename enable_if<is_same<typename Z_p<U>::Type, int64_t>::value, Z_p>::type &operator*=(const Z_p &rhs){
		int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template<typename U = T>
	typename enable_if<!is_integral<typename Z_p<U>::Type>::value, Z_p>::type &operator*=(const Z_p &rhs){
		value = normalize(value * rhs.value);
		return *this;
	}
	Z_p operator^(long long e) const{
		Z_p b = *this, res = 1;
		if(e < 0) b = 1 / b, e = -e;
		for(; e; b *= b, e >>= 1) if(e & 1) res *= b;
		return res;
	}
	Z_p &operator^=(const long long &e){ return *this = *this ^ e; }
	Z_p &operator/=(const Z_p &otr){
		Type a = otr.value, m = mod(), u = 0, v = 1;
		if(a < int(mod_inv.size())) return *this *= mod_inv[a];
		while(a){
			Type t = m / a;
			m -= t * a; swap(a, m);
			u -= t * v; swap(u, v);
		}
		assert(m == 1);
		return *this *= u;
	}
	template<typename U> friend const Z_p<U> &abs(const Z_p<U> &v){ return v; }
	Type value;
};
template<typename T> bool operator==(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const Z_p<T>& lhs, U rhs){ return lhs == Z_p<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) == rhs; }
template<typename T> bool operator!=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const Z_p<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> Z_p<T> operator+(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(const Z_p<T> &lhs, U rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T> Z_p<T> operator-(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T> Z_p<T> operator*(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T> Z_p<T> operator/(const Z_p<T> &lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(const Z_p<T>& lhs, U rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(U lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, Z_p<T> &number){
	typename common_type<typename Z_p<T>::Type, int64_t>::type x;
	in >> x;
	number.value = Z_p<T>::normalize(x);
	return in;
}
template<typename T> ostream &operator<<(ostream &out, const Z_p<T> &number){ return out << number(); }

/*
using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using Zp = Z_p<VarMod>;
*/

constexpr int mod = 1e9 + 7;
//constexpr int mod = (119 << 23) + 1;
using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;

template<typename T> vector<typename Z_p<T>::Type> Z_p<T>::mod_inv;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void precalc_inverse(size_t SZ){
	auto &inv = Z_p<T>::mod_inv;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / int(inv.size()) * inv[mod % int(inv.size())] % mod) % mod);
}

template<class Q, Q (*merge)(Q, Q), Q (*identity)()>
struct segment_tree{
	segment_tree(): segment_tree(0){}
	segment_tree(int n): segment_tree(vector<Q>(n)){}
	segment_tree(const vector<Q> &v): n((int)v.size()){ // O(n)
		log = __lg(n + 1) + 1, size = 1 << log;
		val = vector<Q>(size << 1, identity());
		copy(v.begin(), v.end(), val.begin() + size);
		for(int i = size - 1; i >= 1; -- i) refresh(i);
	}
	void set(int p, Q x){ // O(log n)
		assert(0 <= p && p < n);
		val[p += size] = x;
		for(int i = 1; i <= log; ++ i) refresh(p >> i);
	}
	Q query(int p){ // O(1)
		assert(0 <= p && p < n);
		return val[p + size];
	}
	Q query(int l, int r){ // O(log n)
		assert(0 <= l && l <= r && r <= n);
		Q sml = identity(), smr = identity();
		for(l += size, r += size; l < r; l >>= 1, r >>= 1){
			if(l & 1) sml = merge(sml, val[l ++]);
			if(r & 1) smr = merge(val[-- r], smr);
		}
		return merge(sml, smr);
	}
	Q query_all(){ return val[1]; } // O(1)
	template<class F> int max_pref(int l, F f){ // O(log n)
		assert(0 <= l && l <= n);
		if(l == n) return n;
		l += size;
		Q sm = identity();
		do{
			while(~l & 1) l >>= 1;
			if(!f(merge(sm, val[l]))){
				while(l < size){
					l = l << 1;
					if(f(merge(sm, val[l]))) sm = merge(sm, val[l ++]);
				}
				return l - size;
			}
			sm = merge(sm, val[l ++]);
		}while((l & -l) != l);
		return n;
	} // f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	template<class F> int min_suff(int r, F f){ // O(log n)
		assert(0 <= r && r <= n);
		if(r == 0) return 0;
		r += size;
		Q sm = identity();
		do{
			-- r;
			while (r > 1 && r & 1) r >>= 1;
			if(!f(merge(val[r], sm))){
				while(r < size){
					r = r << 1 | 1;
					if(f(merge(val[r], sm))) sm = merge(val[r --], sm);
				}
				return r + 1 - size;
			}
			sm = merge(val[r], sm);
		}while((r & -r) != r);
		return 0;
	} // f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns min l with T
	int n, size, log;
	vector<Q> val;
	void refresh(int i){ val[i] = merge(val[i << 1], val[i << 1 | 1]); }
};
struct Q{
	Zp ans = 0; // ans stores a[0]w[0] + a[1]w[1] + ... + a[len-1]w[len-1]
	long long sum = 0;
};
Q merge(Q x, Q y){ // merges adjacent intervals
	return {x.ans + y.ans, x.sum + y.sum};
}
Q identity(){ // Monoid Identity
	return {};
}
//	segment_tree<Q, merge, identity> seg(a);

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], a[i] -= i + 1;
	}
	vector<Q> w(n);
	for(auto i = 0; i < n; ++ i){
		cin >> w[i].sum, w[i].ans = a[i] * w[i].sum;
	}
	segment_tree<Q, merge, identity> seg(w);
	for(auto qi = 0; qi < qn; ++ qi){
		int x, y;
		cin >> x >> y;
		if(x < 0){
			x = -x - 1;
			seg.set(x, {Zp(a[x]) * y, y});
		}
		else{
			-- x; // calculate for [x, y)
			long long tot = seg.query(x, y).sum;
			int m = seg.max_pref(x, [&](auto pref){ return 2 * pref.sum <= tot; });
			assert(m < y);
			auto l = seg.query(x, m), r = seg.query(m + 1, y);
			cout << a[m] * Zp(l.sum) - l.ans + r.ans - a[m] * Zp(r.sum) << "\n";
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