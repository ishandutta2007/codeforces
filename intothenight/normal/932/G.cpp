#include <bits/stdc++.h>
using namespace std;

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

// Each node represents a unique palindromic substring plus 0 and 1 node representing empty even and odd string
// Adjacency_Type: array<int, X> or map<Char_Type, int> where X is the size of the alphabet
template<class Char_Type, class Adjacency_Type>
struct palindrome_automaton{
	// Begin States
	// len: length of the palindrome
	// link: suffix link
	// serial_link[u]: longest proper suffix v with len[u] - len[link[u]] != len[v] - len[link[v]]
	// depth: # of suffix links till root
	// occurence: # of occurences of the palindrome as a longest proper palindromic suffix of a prefix
	vector<int> len{0, -1}, link{1, 0}, serial_link{0, 0}, depth{0, 0}, occurence{1, 0};
	vector<Adjacency_Type> next = vector<Adjacency_Type>(2);
	// End States
	vector<Char_Type> s{-1};
	vector<int> last{0};
	long long palindromic_substring_count = 0;
	int new_state(int l, int u){
		len.push_back(l);
		link.push_back(u);
		serial_link.push_back(l - len[u] == len[u] - len[link[u]] ? serial_link[u] : u);
		depth.push_back(depth[u] + 1);
		next.emplace_back();
		occurence.push_back(0);
		return (int)len.size() - 1;
	}
	void extend(const vector<Char_Type> &s){
		for(auto c: s) extend(c);
	}
	void extend(Char_Type c){
		s.push_back(c);
		int l = last.back();
		while(s[(int)s.size() - len[l] - 2] != s.back()) l = link[l];
		if(!next[l][c]){
			int u = link[l];
			while(s[(int)s.size() - len[u] - 2] != s.back()) u = link[u];
			int v = new_state(len[l] + 2, next[u][c]);
			next[l][c] = v; // Separated for UB in C++14 or below
		}
		last.push_back(next[l][c]);
		palindromic_substring_count += depth[last.back()];
		++ occurence[last.back()];
	}
	int size() const{ // # of states
		return (int)len.size();
	}
	// count: # of occurences of the palindrome
	vector<int> count;
	vector<vector<int>> inv_link;
	void init_count(){
		count = occurence, inv_link.assign(size(), {});
		for(auto u = 2; u < (int)size(); ++ u) inv_link[link[u]].push_back(u);
		auto dfs = [&](auto self, int u)->void{
			for(auto v: inv_link[u]) self(self, v), count[u] += count[v];
		};
		dfs(dfs, 0);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string temp;
	cin >> temp;
	int n = (int)temp.size();
	vector<int> s;
	for(auto l = 0, r = n - 1; l < r; ++ l, -- r){
		s.push_back(temp[l] - 'a');
		s.push_back(temp[r] - 'a');
	}
	const int mx = 26;
	palindrome_automaton<int, array<int, mx>> aut;
	aut.extend(s);
	vector<Zp> dp(n + 1);
	vector<array<Zp, 2>> series_dp((int)aut.size());
	dp[0] = 1;
	for(auto len = 1; len <= n; ++ len){
		for(auto u = aut.last[len]; u; u = aut.serial_link[u]){
			series_dp[u] = {};
			int t = aut.len[aut.serial_link[u]] + aut.len[u] - aut.len[aut.link[u]];
			series_dp[u][t & 1] += dp[len - t];
			if(aut.len[u] - aut.len[aut.link[u]] == aut.len[aut.link[u]] - aut.len[aut.link[aut.link[u]]]){
				int p = aut.len[u] - aut.len[aut.link[u]] & 1;
				for(auto t = 0; t < 2; ++ t){
					series_dp[u][t] += series_dp[aut.link[u]][t ^ p];
				}
			}
			dp[len] += series_dp[u][0];
		}
	}
	cout << dp[n] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////