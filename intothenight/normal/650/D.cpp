#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

template<typename T>
struct Z_p{
	using Type = typename decay<decltype(T::value)>::type;
	static vector<Type> MOD_INV;
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
	template<typename U>
	Z_p &operator^=(U e){
		if(e < 0) *this = 1 / *this, e = -e;
		Z_p res = 1;
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	template<typename U>
	Z_p operator^(U e) const{
		return Z_p(*this) ^= e;
	}
	Z_p &operator/=(const Z_p &otr){
		Type a = otr.value, m = mod(), u = 0, v = 1;
		if(a < (int)MOD_INV.size()) return *this *= MOD_INV[a];
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

constexpr int mod = 1e9 + 7; // 1000000007
// constexpr int mod = (119 << 23) + 1; // 998244353
// constexpr int mod = 1e9 + 9; // 1000000009
using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;

template<typename T> vector<typename Z_p<T>::Type> Z_p<T>::MOD_INV;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void precalc_inverse(int SZ){
	auto &inv = Z_p<T>::MOD_INV;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / (int)inv.size() * inv[mod % (int)inv.size()]) % mod);
}

template<typename T>
vector<T> precalc_power(T base, int SZ){
	vector<T> res(SZ + 1, 1);
	for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
	return res;
}

// Process the longest subsequence s0, ..., s(k-1) satisfying cmp(s0, s1) && ... && cmp(s(k-2), s(k-1))
template<class T, class U = int, class Compare = less<>>
struct longest_monotone_subsequence_processor{
	Compare cmp;
	// less: longest increasing subsequence
	// less_equal: longest non-decreasing subsequence
	// greater: longest decreasing subsequence
	// greater_equal: longest non-increasing subsequence
	int n = 0;
	vector<T> sequence;
	vector<int> active; // position of the optimal last element among monotone sequences of length i+1
	vector<int> prev; // second-to-last element of the longest monotone sequence ending at i, -1 if non exists
	vector<int> length; // length of the longest monotone subsequence ending at i
	vector<U> count; // number of the longest monotone subsequences ending at i
	vector<vector<int>> classes = vector<vector<int>>(1); // classes[len]: set of indices i where length[i] = len (in increasing order)
	vector<int> aux_it = vector<int>(1); // auxiliary position array for counting
	vector<U> aux_sum = vector<U>{1}; // auxiliary sum array for counting
	longest_monotone_subsequence_processor(Compare cmp = less<>()){ }
	longest_monotone_subsequence_processor(const vector<T> &a, Compare cmp = less<>()){
		insert(a);
	}
	void insert(const vector<T> &a){
		for(auto x: a) insert(x);
	}
	void insert(T x){ // O(log n)
		int i = n ++;
		sequence.push_back(x);
		prev.push_back(-1);
		length.push_back(-1);
		count.push_back(0);
		auto it = partition_point(active.begin(), active.end(), [&](int i){ return cmp(sequence[i], x); });
		if(it == active.end()){
			active.emplace_back();
			classes.emplace_back();
			aux_it.emplace_back();
			aux_sum.emplace_back();
			it = std::prev(active.end());
		}
		*it = i;
		prev[i] = it == active.begin() ? -1 : *std::prev(it);
		int len = length[i] = it - active.begin() + 1;
		while(aux_it[len - 1] < (int)classes[len - 1].size() && !cmp(sequence[classes[len - 1][aux_it[len - 1]]], x)){
			aux_sum[len - 1] -= count[classes[len - 1][aux_it[len - 1] ++]];
		}
		count[i] = aux_sum[len - 1];
		classes[len].push_back(i);
		aux_sum[len] += count[i];
	}
	int lms_length() const{
		return (int)active.size();
	}
	vector<int> lms_indices() const{
		int len = lms_length(), i = active.back();
		vector<int> res(len);
		while(len --) res[len] = i, i = prev[i];
		return res;
	}
	vector<T> lms() const{
		vector<T> res;
		res.reserve(lms_length());
		for(auto i: lms_indices()) res.push_back(sequence[i]);
		return res;
	}
	U lms_count() const{
		U res = 0;
		int len = lms_length();
		for(auto i = 0; i < n; ++ i) if(length[i] == len) res += count[i];
		return res;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> h(n);
	for(auto i = 0; i < n; ++ i){
		cin >> h[i];
	}
	vector<vector<array<int, 2>>> query(n);
	for(auto qi = 0; qi < qn; ++ qi){
		int i, x;
		cin >> i >> x, -- i;
		query[i].push_back({x, qi});
	}
	vector<int> res(qn, 1);
	longest_monotone_subsequence_processor<int, Zp> left;
	for(auto i = 0; i < n; ++ i){
		for(auto [x, qi]: query[i]){
			res[qi] += partition_point(left.active.begin(), left.active.end(), [&](int i){ return h[i] < x; }) - left.active.begin();
		}
		left.insert(h[i]);
	}
	auto lis = left.lms_indices();
	vector<bool> in_lis(n);
	for(auto i: lis){
		in_lis[i] = true;
	}
	Zp tot = left.lms_count();
	auto right = longest_monotone_subsequence_processor<int, Zp, greater<>>(greater<>());
	for(auto i = n - 1; i >= 0; -- i){
		for(auto [x, qi]: query[i]){
			res[qi] += partition_point(right.active.begin(), right.active.end(), [&](int i){ return h[n - 1 - i] > x; }) - right.active.begin();
		}
		right.insert(h[i]);
	}
	for(auto i = 0; i < n; ++ i){
		int cur = (int)lis.size() - (in_lis[i] && tot == left.count[i] * right.count[n - 1 - i]);
		for(auto [x, qi]: query[i]){
			ctmax(res[qi], cur);
		}
	}
	for(auto x: res){
		cout << x << "\n";
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