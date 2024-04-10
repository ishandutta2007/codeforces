#include <bits/stdc++.h>
using namespace std;

template<class Q, Q (*merge)(Q, Q), Q (*identity)()>
struct sparse_table_base{
	int n;
	vector<vector<Q>> val;
	sparse_table_base(vector<Q> &a): n((int)a.size()), val({a}){ // O(n log n)
		for(int p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			val.emplace_back(n - (p << 1) + 1);
			for(int j = 0; j < (int)val[i].size(); ++ j) val[i][j] = merge(val[i - 1][j], val[i - 1][j + p]);
		}
	}
	sparse_table_base(){ }
	Q query(int l, int r){ // O(1)
		if(l >= r) return identity();
		int d = __lg(r - l);
		return merge(val[d][l], val[d][r - (1 << d)]);
	}
};
template<class Q> Q st_merge(Q x, Q y){ // Must be idempotent
	return min(x, y);
}
template<class Q> Q st_id(){
	return numeric_limits<Q>::max() / 2;
}
template<class Q>
using sparse_table = sparse_table_base<Q, st_merge<Q>, st_id<Q>>;

// Requires sparse_table
struct suffix_array{
	int n;
	vector<int> sa, rank, lcp;
	// sa[i]: index of suffix of s at position i, rank[i]: position of suffix i, lcp[i]: lcp[i] = lcp of suffices at i and i+1
	sparse_table<int> rmq;
	template<class Str>
	suffix_array(const Str &s, int lim = 256): n((int)s.size() + 1), sa(n), rank(n), lcp(n){
		int n = (int)s.size() + 1, k = 0, a, b;
		vector<int> x(s.begin(), s.end() + 1), y(n), ws(max(n, lim));
		iota(sa.begin(), sa.end(), 0);
		for(auto j = 0, p = 0; p < n; j = max(1, j * 2), lim = p){
			p = j, iota(y.begin(), y.end(), n - j);
			for(auto i = 0; i < n; ++ i) if(sa[i] >= j) y[p ++] = sa[i] - j;
			fill(ws.begin(), ws.end(), 0);
			for(auto i = 0; i < n; ++ i) ws[x[i]] ++;
			for(auto i = 1; i < lim; ++ i) ws[i] += ws[i - 1];
			for(auto i = n; i --; ) sa[-- ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			for(auto i = 1; i < n; ++ i){
				a = sa[i - 1], b = sa[i];
				x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p ++;
			}
		}
		for(auto i = 1; i < n; ++ i) rank[sa[i]] = i;
		for(int i = 0, j; i < n - 1; lcp[rank[i ++]] = k) for(k && k --, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k ++);
		sa.erase(sa.begin()), rank.pop_back(), lcp.erase(lcp.begin(), lcp.begin() + 2), -- n;
		for(auto &r: rank) -- r;
		rmq = {lcp};
	}
	int query(int i, int j){ // Find the length of lcp of suffices starting at i and j
		return i == j ? n - 1 - max(i, j) : rmq.query(min(rank[i], rank[j]), max(rank[i], rank[j]));
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, k;
		string s;
		cin >> n >> k >> s;
		for(auto &c: s){
			c ^= 1;
		}
		suffix_array sa(s);
		int i = 0;
		while(n - sa.sa[i] < k){
			++ i;
		}
		string c(k, '0');
		if(s.substr(sa.sa[i], k) != c){
			cout << "YES\n" << c << "\n";
			return 0;
		}
		while(true){
			int d = k - 1;
			while(d >= 0 && c[d] == '1'){
				-- d;
			}
			if(d < 0){
				cout << "NO\n";
				return 0;
			}
			for(auto i = d; i < k; ++ i){
				c[i] ^= 1;
			}
			int j = i + 1;
			while(j < n && (n - sa.sa[j] < k || sa.query(sa.sa[i], sa.sa[j]) > d)){
				++ j;
			}
			if(j == n || sa.query(sa.sa[i], sa.sa[j]) < d || s.substr(sa.sa[j] + d, k - d) != c.substr(d)){
				cout << "YES\n" << c << "\n";
				return 0;
			}
			i = j;
		}
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