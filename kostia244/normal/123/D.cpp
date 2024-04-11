#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
const int maxn = 1e5 + 55;
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
		return rmq.query(min(i, j), max(i, j));
	}
};
using S = suffix_array<string>;
string str;
map<ll, ll> mp;
ll sm = 0;
void add(int x) {
	mp[x]++;
	sm += x;
	while(mp.begin()->first < x) {
		auto t = *mp.begin();
		mp.erase(mp.begin());
		sm += (-t.first+x)*t.second;
		mp[x] += t.second;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	ll n = str.size();
	S sa(str);
	ll ans = n*(n+1)/2;
	for(int i = 1; i < n; i++) add(-sa.lcp(i, i-1)), ans -= sm;
	cout << ans;
}