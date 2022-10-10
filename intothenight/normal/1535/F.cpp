#include <bits/stdc++.h>
using namespace std;

// Specialization of sparse_table
// Range min query by default. Set cmp = greater for max query
template<class T, class Compare = less<>>
struct range_minmax_query_solver{
	int n;
	vector<vector<T>> data;
	Compare cmp;
	T T_id;
	range_minmax_query_solver(){ }
	range_minmax_query_solver(const vector<T> &a, Compare cmp = less<>(), T T_id = numeric_limits<T>::max()): n((int)a.size()), cmp(cmp), T_id(T_id), data({a}){ // O(n log n)
		for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			data.emplace_back(n - (p << 1) + 1);
			for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = cmp(data[i - 1][j], data[i - 1][j + p]) ? data[i - 1][j] : data[i - 1][j + p];
		}
	}
	T query(int l, int r) const{ // O(1)
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return T_id;
		int d = __lg(r - l);
		return cmp(data[d][l], data[d][r - (1 << d)]) ? data[d][l] : data[d][r - (1 << d)];
	}
};

// Requires range_minmax_query_solver
struct suffix_array{
	template<class T>
	void compute_lcp(const vector<T> &s){
		assert(1 <= n);
		rank.resize(n), lcp.resize(n - 1);
		for(auto i = 0; i < n; ++ i) rank[sa[i]] = i;
		for(auto i = 0, h = 0; i < n; ++ i){
			if(h > 0) -- h;
			if(rank[i] == 0) continue;
			int j = sa[rank[i] - 1];
			for(; j + h < n && i + h < n; ++ h) if(s[j + h] != s[i + h]) break;
			lcp[rank[i] - 1] = h;
		}
		rmq = range_minmax_query_solver(lcp);
	} // O(n log n)
	vector<int> sa_naive(const vector<int> &s){
		int n = (int)s.size();
		vector<int> sa(n);
		iota(sa.begin(), sa.end(), 0);
		sort(sa.begin(), sa.end(), [&](int l, int r){
			if(l == r) return false;
			for(; l < n && r < n; ++ l, ++ r) if(s[l] != s[r]) return s[l] < s[r];
			return l == n;
		});
		return sa;
	}
	vector<int> sa_doubling(const vector<int> &s){
		int n = (int)s.size();
		vector<int> sa(n), rank = s, tmp(n);
		iota(sa.begin(), sa.end(), 0);
		for(auto k = 1; k < n; k <<= 1){
			auto cmp = [&](int x, int y){
				if(rank[x] != rank[y]) return rank[x] < rank[y];
				int rx = x + k < n ? rank[x + k] : -1;
				int ry = y + k < n ? rank[y + k] : -1;
				return rx < ry;
			};
			sort(sa.begin(), sa.end(), cmp);
			tmp[sa[0]] = 0;
			for(auto i = 1; i < n; ++ i) tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
			swap(tmp, rank);
		}
		return sa;
	}
	template<int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
	vector<int> sa_is(const vector<int> &s, int upper){
		int n = (int)s.size();
		if(n == 0) return {};
		if(n == 1) return {0};
		if(n == 2){
			if(s[0] < s[1]) return {0, 1};
			else return {1, 0};
		}
		if(n < THRESHOLD_NAIVE) return sa_naive(s);
		if(n < THRESHOLD_DOUBLING) return sa_doubling(s);
		vector<int> sa(n);
		vector<bool> ls(n);
		for(auto i = n - 2; i >= 0; -- i) ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
		vector<int> sum_l(upper), sum_s(upper);
		for(auto i = 0; i < n; ++ i){
			if(!ls[i]) ++ sum_s[s[i]];
			else ++ sum_l[s[i] + 1];
		}
		for(auto i = 0; i < upper; ++ i){
			sum_s[i] += sum_l[i];
			if(i + 1 < upper) sum_l[i + 1] += sum_s[i];
		}
		auto induce = [&](const vector<int> &lms){
			fill(sa.begin(), sa.end(), -1);
			vector<int> buf(upper);
			copy(sum_s.begin(), sum_s.end(), buf.begin());
			for(auto d: lms){
				if(d == n) continue;
				sa[buf[s[d]] ++] = d;
			}
			copy(sum_l.begin(), sum_l.end(), buf.begin());
			sa[buf[s[n - 1]] ++] = n - 1;
			for(auto i = 0; i < n; ++ i){
				int v = sa[i];
				if(v >= 1 && !ls[v - 1]) sa[buf[s[v - 1]] ++] = v - 1;
			}
			copy(sum_l.begin(), sum_l.end(), buf.begin());
			for(auto i = n - 1; i >= 0; -- i){
				int v = sa[i];
				if(v >= 1 && ls[v - 1]) sa[-- buf[s[v - 1] + 1]] = v - 1;
			}
		};
		vector<int> lms_map(n + 1, -1);
		int m = 0;
		for(auto i = 1; i < n; ++ i) if(!ls[i - 1] && ls[i]) lms_map[i] = m ++;
		vector<int> lms;
		lms.reserve(m);
		for(auto i = 1; i < n; ++ i) if(!ls[i - 1] && ls[i]) lms.push_back(i);
		induce(lms);
		if(m){
			vector<int> sorted_lms;
			sorted_lms.reserve(m);
			for(auto v: sa) if(lms_map[v] != -1) sorted_lms.push_back(v);
			vector<int> rec_s(m);
			int rec_upper = 0;
			rec_s[lms_map[sorted_lms[0]]] = 0;
			for(auto i = 1; i < m; ++ i){
				int l = sorted_lms[i - 1], r = sorted_lms[i];
				int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
				int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
				bool same = true;
				if(end_l - l != end_r - r) same = false;
				else{
					for(; l < end_l; ++ l, ++ r) if (s[l] != s[r]) break;
					if(l == n || s[l] != s[r]) same = false;
				}
				if(!same) ++ rec_upper;
				rec_s[lms_map[sorted_lms[i]]] = rec_upper;
			}
			auto rec_sa = sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper + 1);
			for(auto i = 0; i < m; ++ i) sorted_lms[i] = lms[rec_sa[i]];
			induce(sorted_lms);
		}
		return sa;
	}
	int n;
	vector<int> sa, rank, lcp;
	range_minmax_query_solver<int> rmq;
	suffix_array(const vector<int> &s, int upper, bool prepare_lcp): n((int)s.size()){
		assert(0 <= upper);
		for(auto d: s) assert(0 <= d && d < upper);
		sa = sa_is(s, upper);
		if(prepare_lcp) compute_lcp(s);
	} // O(n + upper) without compute_lcp
	template<class T>
	suffix_array(const vector<T> &s, bool prepare_lcp): n((int)s.size()){
		vector<int> idx(n);
		iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), [&](int l, int r){ return s[l] < s[r]; });
		vector<int> s2(n);
		int now = 0;
		for(auto i = 0; i < n; ++ i){
			if(i && s[idx[i - 1]] != s[idx[i]]) ++ now;
			s2[idx[i]] = now;
		}
		sa = sa_is(s2, now + 1);
		if(prepare_lcp) compute_lcp(s);
	} // O(n log n) time, O(n) space without compute_lcp
	int query(int i, int j){
		if(i == j) return n - i;
		return rmq.query(min(rank[i], rank[j]), max(rank[i], rank[j]));
	}
};

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

using namespace chrono;
#ifdef LOCAL
mt19937 rng(1);
#else
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
#endif

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
	cin >> n;
	vector<string> a(n);
	const int mx = 26;
	vector<vector<array<int, mx>>> cnt(n);
	map<array<int, mx>, vector<int>> s;
	string cc, rcc;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		{
			cc += a[i];
			auto ra = a[i];
			reverse(ra.begin(), ra.end());
			rcc += ra;
		}
		m = (int)a[i].size();
		cnt[i].resize(m + 1);
		for(auto j = 0; j < m; ++ j){
			cnt[i][j + 1] = cnt[i][j];
			++ cnt[i][j + 1][a[i][j] - 'a'];
		}
		s[cnt[i][m]].push_back(i);
	}
	suffix_array sa({cc.begin(), cc.end()}, 300, true);
	suffix_array rsa({rcc.begin(), rcc.end()}, 300, true);
	auto lcpref = [&](int i, int j)->int{
		assert(0 <= i && i < j && j < n);
		return sa.query(i * m, j * m);
	};
	auto lcsuff = [&](int i, int j)->int{
		assert(0 <= i && i < j && j < n);
		return rsa.query(i * m, j * m);
	};
	long long res = 0;
	for(auto [ignore, v]: s){
		{
			static int aux_pref = 0;
			res += 1337LL * aux_pref * (int)v.size();
			aux_pref += (int)v.size();
		}
		#ifdef LOCAL
		// static const int th = numeric_limits<int>::max();
		static const int th = -1;
		#else
		static const int th = sqrt(2e5) * 10;
		#endif
		if((int)v.size() <= th){
			for(auto i = 0; i < (int)v.size(); ++ i){
				for(auto j = i + 1; j < (int)v.size(); ++ j){
					if(lcpref(v[i], v[j]) < m){
						int l = lcpref(v[i], v[j]), r = m - lcsuff(v[i], v[j]);
						if(is_sorted(a[v[i]].begin() + l, a[v[i]].begin() + r) || is_sorted(a[v[j]].begin() + l, a[v[j]].begin() + r)){
							res += 1;
						}
						else{
							res += 2;
						}
					}
				}
			}
		}
		else{
			debug("\n");
			debug(v);
			const Zp base1 = rng() % 10000000 + 1000;
			const Zp base2 = rng() % 10000000 + 1000;
			const Zp invbase1 = 1 / (base1 - 1);
			const Zp invbase2 = 1 / (base2 - 1);
			auto power1 = precalc_power(base1, m);
			auto power2 = precalc_power(base2, m);
			static vector<vector<Zp>> hash1(n, vector<Zp>(m + 1));
			static vector<vector<Zp>> hash2(n, vector<Zp>(m + 1));
			vector<pair<array<int, 2>, int>> order;
			for(auto i: v){
				for(auto j = 0; j < m; ++ j){
					hash1[i][j + 1] = hash1[i][j] + power1[j] * a[i][j];
					hash2[i][j + 1] = hash2[i][j] + power2[j] * a[i][j];
				}
				order.push_back({{hash1[i][m].value, hash2[i][m].value}, i});
			}
			sort(order.begin(), order.end());
			long long zeroes = 0;
			{
				for(auto i = 0, j = 0; i < (int)v.size(); ){
					while(i == j || j < (int)v.size() && order[j - 1].first == order[j].first){
						zeroes += j - i;
						++ j;
					}
					i = j;
				}
			}
			debug(zeroes);
			long long ones = 0;
			{
				for(auto i: v){
					static vector<array<int, 2>> hashes;
					hashes.clear();
					for(auto l = 0; l < m; ++ l){
						bool sorted = true;
						for(auto r = l + 2; r <= m; ++ r){
							if(a[i][r - 2] > a[i][r - 1]){
								sorted = false;
							}
							if(!sorted){
								Zp val1 = hash1[i][m] - hash1[i][r] + hash1[i][l];
								Zp val2 = hash2[i][m] - hash2[i][r] + hash2[i][l];
								for(auto c = 0, p = l; c < mx; ++ c){
									int x = cnt[i][r][c] - cnt[i][l][c];
									val1 += (c + 'a') * (power1[p + x] - power1[p]) * invbase1;
									val2 += (c + 'a') * (power2[p + x] - power2[p]) * invbase2;
									p += x;
								}
								hashes.push_back({val1.value, val2.value});
							}
						}
					}
					sort(hashes.begin(), hashes.end());
					hashes.erase(unique(hashes.begin(), hashes.end()), hashes.end());
					for(auto val: hashes){
						auto [a, b] = equal_range(order.begin(), order.end(), pair{val, -1}, [&](const auto &x, const auto &y){ return x.first < y.first; });
						ones += b - a;
					}
				}
			}
			debug(ones);
			res += 1LL * (int)v.size() * ((int)v.size() - 1) - ones - 2 * zeroes;
		}
		debug(res, "\n");
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