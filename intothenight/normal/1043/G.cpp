#include "bits/stdc++.h"
using namespace std;

template<int SZ>
struct number_theory{
	// least prime factor, primes, mobius function, totient function, number of multiples
	vector<int> lpf, prime, mu, phi;
	// O(SZ)
	number_theory(): lpf(SZ + 1), mu(SZ + 1, 1), phi(SZ + 1, 1){
		for(int i = 2; i <= SZ; ++ i){
			if(!lpf[i]) lpf[i] = i, prime.push_back(i);
			if(i / lpf[i] % lpf[i]) mu[i] = -mu[i / lpf[i]], phi[i] = phi[i / lpf[i]] * (lpf[i] - 1);
			else mu[i] = 0, phi[i] = phi[i / lpf[i]] * lpf[i];
			for(int j = 0; j < int(prime.size()) && prime[j] <= lpf[i] && prime[j] * i <= SZ; ++ j) lpf[prime[j] * i] = prime[j];
		}
	}
};

template<typename T, typename BO>
struct sparse_table{
	int n;
	BO bin_op;
	T id;
	vector<vector<T>> val;
	template<typename IT>
	sparse_table(IT begin, IT end, BO bin_op, T id): n(distance(begin, end)), bin_op(bin_op), id(id), val(1, {begin, end}){
		for(int p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			val.emplace_back(n - (p << 1) + 1);
			for(int j = 0; j < int(val[i].size()); ++ j) val[i][j] = min(val[i - 1][j], val[i - 1][j + p]);
		}
	}
	sparse_table(){ }
	T query(int l, int r){
		if(l >= r) return id;
		int d = __lg(r - l);
		return bin_op(val[d][l], val[d][r - (1 << d)]);
	}
};
template<typename Str>
struct suffix_array{
	int n;
	vector<int> sa, rank, lcp;
	// sa[i]: indices of suffix of s+delim at position i, rank: inverse of sa, lcp[i]: lcp[0]=0, lcp[i] = lcp of suffices at i-1 and i
	sparse_table<int, function<int(int, int)>> rmq;
	suffix_array(const Str &s, int lim = 256): n(int(s.size()) + 1), sa(n), rank(n), lcp(n){
		int n = int(s.size()) + 1, k = 0, a, b;
		vector<int> x(s.begin(), s.end() + 1), y(n), ws(max(n, lim));
		iota(sa.begin(), sa.end(), 0);
		for(int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p){
			p = j, iota(y.begin(), y.end(), n - j);
			for(int i = 0; i < n; ++ i) if(sa[i] >= j) y[p ++] = sa[i] - j;
			fill(ws.begin(), ws.end(), 0);
			for(int i = 0; i < n; ++ i) ws[x[i]] ++;
			for(int i = 1; i < lim; ++ i) ws[i] += ws[i - 1];
			for(int i = n; i --; ) sa[-- ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			for(int i = 1; i < n; ++ i){
				a = sa[i - 1], b = sa[i];
				x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p ++;
			}
		}
		for(int i = 1; i < n; ++ i) rank[sa[i]] = i;
		for(int i = 0, j; i < n - 1; lcp[rank[i ++]] = k) for(k && k --, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++);
		rmq = sparse_table<int, function<int(int, int)>>(lcp.begin(), lcp.end(), [&](int x, int y){ return min(x, y); }, numeric_limits<int>::max());
	}
	int query(int i, int j){ // Find the length of lcp of suffices starting at i and j
		return i == j ? n - 1 - max(i, j) : rmq.query(min(rank[i], rank[j]) + 1, max(rank[i], rank[j]) + 1);
	}
};
template<typename Str, typename SA>
vector<array<int,3>> main_lorentz(const Str &s, SA &sa){
	int n = int(s.size());
	suffix_array rsa(Str(s.rbegin(), s.rend()));
	vector<array<int,3>> res;
	for(int p = 1; p << 1 <= n; ++ p){ // do in O(n / p) for period p
		for(int i = 0, lst = -1; i + p <= n; i += p){
			int l = i - rsa.query(n - i - p, n - i), r = i - p + sa.query(i, i + p);
			if(l > r || l == lst) continue;
			res.push_back({lst = l, r + 1, p});
		} // s.substr(i, p) == s.substr(i + p, p) for each i in [l, r)
	}
	return res;
}

template<typename T, typename BO>
struct reverse_segment_tree{
	int n;
	BO bin_op;
	T id;
	vector<T> val;
	vector<int> roots;
	template<typename IT>
	reverse_segment_tree(IT begin, IT end, BO bin_op, T id): n(distance(begin, end)), bin_op(bin_op), id(id), val(n << 1, id){
		for(int i = 0; i < n; ++ i) val[i + n] = *(begin ++);
	}
	reverse_segment_tree(int n, BO bin_op, T id): n(n), bin_op(bin_op), id(id), val(n << 1, id){ }
	void init_roots(){
		vector<int> roots_r;
		for(auto l = n, r = n << 1; l < r; l >>= 1, r >>= 1){
			if(l & 1) roots.push_back(l ++);
			if(r & 1) roots_r.push_back(-- r);
		}
		roots.insert(roots.end(), roots_r.rbegin(), roots_r.rend());
	}
	void update(int l, int r, T x){
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) val[l ++] = bin_op(val[l], x);
			if(r & 1) val[r] = bin_op(val[-- r], x);
		}
	}
	T query(int p){
		T res = id;
		for(p += n; p > 0; p >>= 1) res = bin_op(res, val[p]);
		return res;
	}
	void push(){
		for(int i = 1; i < n; ++ i){
			val[i << 1] = bin_op(val[i << 1], val[i]);
			val[i << 1 | 1] = bin_op(val[i << 1 | 1], val[i]);
			val[i] = id;
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	number_theory<200000> nt;
	int n, qq;
	string s;
	cin >> n >> s >> qq;
	vector<vector<int>> cnt(n + 1, vector<int>(26));
	for(auto i = 0; i < n; ++ i){
		for(auto c = 0; c < 26; ++ c){
			cnt[i + 1][c] = cnt[i][c] + (s[i] == c + 'a');
		}
	}
	int sqrtn = sqrt(n);
	suffix_array sa(s);
	auto tandem = main_lorentz(s, sa);
	reverse_segment_tree rtr(n, [&](int x, int y){ return min(x, y); }, n + 1);
	reverse_segment_tree ltr(n, [&](int x, int y){ return min(x, y); }, n + 1);
	for(auto &[l, r, p]: tandem){
		rtr.update(l, r, 2 * p);
		ltr.update(l + 2 * p - 1, r + 2 * p - 1, 2 * p);
	}
	rtr.push();
	ltr.push();
	vector<int> rb(rtr.val.begin() + n, rtr.val.end()), lb(ltr.val.begin() + n, ltr.val.end());
	// rb[i]: min possible length L where [i, i + L) is a tandem
	// lb[i]: min possible length L where (i - L, i] is a tandem
	vector<int> rightmost(n);
	for(auto i = 0; i < n; ++ i){
		rightmost[i] = rb[i] + i - 1;
	}
	sparse_table st(rightmost.begin(), rightmost.end(), [&](int x, int y){ return min(x, y); }, numeric_limits<int>::max() / 2);
	while(qq --){
		int l, r;
		cin >> l >> r, -- l;
		if(r - l <= 26){
			static vector<int> cnt;
			cnt.assign(26, 0);
			for(auto i = l; i < r; ++ i){
				if(cnt[s[i] - 'a']){
					goto failed_m1;
				}
				++ cnt[s[i] - 'a'];
			}
			cout << "-1\n";
			continue;
		}
		failed_m1:;
		for(int p = r - l; p > 1; p /= nt.lpf[p]){
			int len = (r - l) / nt.lpf[p];
			if(len <= r - l >> 1 && sa.query(l, l + len) >= r - l - len){
				cout << "1\n";
				goto end_of_query;
			}
		}
		if(rb[l] < r - l || lb[r - 1] < r - l){
			cout << "2\n";
			goto end_of_query;
		}
		for(auto len = 1; len <= min(sqrtn, r - l >> 1); ++ len){
			if(sa.query(l, r - len) >= len){
				cout << "2\n";
				goto end_of_query;
			}
		}
		for(auto i = max(1, sa.rank[l] - sqrtn); i <= min(n, sa.rank[l] + sqrtn); ++ i){
			int len = r - sa.sa[i];
			if(len > 0 && len <= r - l >> 1 && sa.query(l, r - len) >= len){
				cout << "2\n";
				goto end_of_query;
			}
		}
		if(st.query(l, r) < r || cnt[r][s[l] - 'a'] - cnt[l + 1][s[l] - 'a'] || cnt[r - 1][s[r - 1] - 'a'] - cnt[l][s[r - 1] - 'a']){
			cout << "3\n";
		}
		else{
			cout << "4\n";
		}
		end_of_query:;
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