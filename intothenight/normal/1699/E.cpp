#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

struct number_theory{
	int SZ;
	vector<int> lpf, prime; // least prime factor, primes, mobius function, totient function, number of multiples
	number_theory(int SZ): SZ(SZ), lpf(SZ + 1){ // O(SZ)
		lpf[0] = lpf[1] = numeric_limits<int>::max() / 2;
		for(auto i = 2; i <= SZ; ++ i){
			if(!lpf[i]) lpf[i] = i, prime.push_back(i);
			for(auto j = 0; j < (int)prime.size() && prime[j] <= lpf[i] && prime[j] * i <= SZ; ++ j) lpf[prime[j] * i] = prime[j];
		}
	}
	vector<int> precalc_mobius() const{
		vector<int> mobius(SZ + 1, 1);
		for(auto i = 2; i <= SZ; ++ i){
			if(i / lpf[i] % lpf[i]) mobius[i] = -mobius[i / lpf[i]];
			else mobius[i] = 0;
		}
		return mobius;
	}
	vector<int> precalc_phi() const{
		vector<int> phi(SZ + 1, 1);
		for(auto i = 2; i <= SZ; ++ i){
			if(i / lpf[i] % lpf[i]) phi[i] = phi[i / lpf[i]] * (lpf[i] - 1);
			else phi[i] = phi[i / lpf[i]] * lpf[i];
		}
		return phi;
	}
	bool is_prime(int x) const{
		assert(0 <= x && x <= SZ);
		return lpf[x] == x;
	}
	int mu_large(long long x) const{ // O(sqrt(x))
		int res = 1;
		for(auto i = 2LL; i * i <= x; ++ i) if(x % i == 0){
			if(x / i % i) return 0;
			x /= i, res = -res;
		}
		if(x > 1) res = -res;
		return res;
	}
	long long phi_large(long long x) const{ // O(sqrt(x))
		long long res = x;
		for(auto i = 2LL; i * i <= x; ++ i) if(x % i == 0){
			while(x % i == 0) x /= i;
			res -= res / i;
		}
		if(x > 1) res -= res / x;
		return res;
	}
	// returns an array is_prime of length high-low where is_prime[i] = [low+i is a prime]
	vector<bool> sieve(long long low, long long high) const{
		assert(high - 1 <= 1LL * SZ * SZ);
		vector<bool> is_prime(high - low, true);
		for(auto p: prime) for(auto x = max(1LL * p, (low + p - 1) / p) * p; x < high; x += p) is_prime[x - low] = false;
		for(auto x = 1; x >= low; -- x) is_prime[x - low] = false;
		return is_prime;
	}
};

template<class T>
struct fenwick_tree_sum{
	int n;
	vector<T> data;
	fenwick_tree_sum(){ }
	// O(n)
	fenwick_tree_sum(int n): n(n), data(n){ }
	// O(n)
	fenwick_tree_sum(int n, T init): fenwick_tree_sum(vector<T>(n, init)){ }
	// O(n)
	fenwick_tree_sum(const vector<T> &v): n((int)v.size()), data(v){
		for(auto i = 1; i <= n; ++ i) if(i + (i & -i) <= n) data[i + (i & -i) - 1] += data[i - 1];
	}
	fenwick_tree_sum(const fenwick_tree_sum &otr): n(otr.n), data(otr.data){
	}
	// O(log n)
	void update(int p, T x){
		assert(0 <= p && p < n);
		for(++ p; p <= n; p += p & -p) data[p - 1] += x;
	}
	// O(log n)
	T pref(int r) const{
		assert(0 <= r && r <= n);
		T s{};
		for(; r > 0; r -= r & -r) s += data[r - 1];
		return s;
	}
	// O(log n)
	T query(int l, int r) const{
		assert(l <= r);
		return pref(r) - pref(l);
	}
	// O(log n)
	T query(int p) const{
		return pref(p + 1) - pref(p);
	}
	// pred(sum[0, r)) is T, T, ..., T, F, F, ..., F
	// Returns max r with T
	// O(log n)
	int max_pref(auto pred) const{
		assert(pred({}));
		int p = 0;
		T sum{};
		for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && pred(sum + data[p + pw - 1])){
			sum += data[p + pw - 1];
			p += pw;
		}
		return p;
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const fenwick_tree_sum<T> &fw){
		out << "[";
		for(auto i = 0; i < fw.n; ++ i){
			out << fw.query(i);
			if(i != fw.n - 1) out << ", ";
		}
		return out << ']';
	}
};

// Efficient multiset when the keys are integers in range [offset, offset + len)
// Requires fenwick_tree_sum
template<class T>
struct integral_multiset{
	int _size = 0;
	T offset, maxval;
	vector<int> freq;
	fenwick_tree_sum<int> data;
	integral_multiset(int len, T offset = {}): offset(offset), maxval(offset + len), freq(len), data(len){ }
	integral_multiset(const vector<T> &init, int len, T offset = 0): offset(offset), maxval(offset + len), freq(len){
		for(auto x: init){
			assert(offset <= x && x < maxval);
			++ freq[x - offset], ++ _size;
		}
		data = {freq};
	}
	integral_multiset(const integral_multiset &otr): _size(otr._size), offset(otr.offset), maxval(otr.maxval), freq(otr.freq), data(otr.data){
	}
	friend ostream &operator<<(ostream &out, integral_multiset ms){
		out << "{";
		for(auto x = ms.offset; x < ms.maxval; ++ x) for(auto rep = 0; rep < ms.freq[x]; ++ rep) out << x << ", ";
		return ms.empty() ? out << "}" : out << "\b\b}";
	}
	// O(1)
	int size() const{
		return _size;
	}
	// O(1)
	bool empty() const{
		return !_size;
	}
	// O(1)
	bool contains(T x) const{
		assert(offset <= x && x < maxval);
		return freq[x - offset];
	}
	// O(1)
	int count(T x) const{
		assert(offset <= x && x < maxval);
		return freq[x - offset];
	}
	// O(log len)
	void insert(T x){
		assert(offset <= x && x < maxval);
		++ _size;
		++ freq[x - offset];
		data.update(x - offset, 1);
	}
	// O(log len) if true, O(1) otherwise
	bool erase(T x){
		assert(offset <= x && x < maxval);
		if(freq[x - offset]){
			-- _size;
			-- freq[x - offset];
			data.update(x - offset, -1);
			return true;
		}
		return false;
	}
	// O(log len)
	T find_by_order(int k) const{
		if(k < 0) return offset - 1;
		if(k >= _size) return maxval;
		return data.max_pref([k](int pref){ return pref <= k; }) + offset;
	}
	// O(log len)
	int order_of_key(T x) const{
		if(x < offset) return 0;
		if(maxval <= x) return _size;
		return data.pref(x - offset);
	}
	// O(log len)
	T front() const{
		assert(_size);
		return find_by_order(0) + offset;
	}
	// O(log len)
	T back() const{
		assert(_size);
		return find_by_order(_size - 1) + offset;
	}
	// Returns maxval if no such element
	// O(log len)
	T lower_bound(T x) const{
		return find_by_order(data.pref(x - offset));
	}
	// O(log len), returns maxval if no such element
	T upper_bound(T x) const{
		return find_by_order(data.pref(x - offset + 1));
	}
	// Returns minval if no such element
	// O(log len)
	T reverse_lower_bound(T x) const{
		return find_by_order(data.pref(x - offset + 1) - 1);
	}
	// Returns minval if no such element
	// O(log len)
	T reverse_upper_bound(T x) const{
		return find_by_order(data.pref(x - offset) - 1);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, m;
		cin >> n >> m;
		number_theory nt(m);
		vector<int> gpf(m + 1);
		nt.lpf[1] = gpf[1] = 1;
		for(auto x = 2; x <= m; ++ x){
			if(nt.is_prime(x)){
				gpf[x] = x;
			}
			else{
				gpf[x] = gpf[x / nt.lpf[x]];
			}
		}
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		ranges::sort(a);
		a.erase(unique(a.begin(), a.end()), a.end());
		n = (int)a.size();
		int res;
		{
			int l = numeric_limits<int>::max();
			int r = numeric_limits<int>::min();
			for(auto x: a){
				ctmin(l, nt.lpf[x]);
				ctmax(r, gpf[x]);
			}
			res = r - l;
		}
		vector<int> dp(m + 1);
		for(auto x = 1; x <= m; ++ x){
			dp[x] = x;
		}
		vector<int> appear(m + 1);
		integral_multiset<int> s(m + 1);
		for(auto x: a){
			appear[x] = true;
			s.insert(dp[x]);
		}
		for(auto low = m; low >= 2; -- low){
			for(auto x = low, y = 1; x <= m; x += low, ++ y){
				int dp_next = y < low ? x : min(dp[x], dp[y]);
				if(appear[x] && dp[x] != dp_next){
					s.erase(dp[x]);
					s.insert(dp_next);
				}
				dp[x] = dp_next;
			}
			if(low <= a[0]){
				ctmin(res, s.back() - low);
			}
		}
		cout << res << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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