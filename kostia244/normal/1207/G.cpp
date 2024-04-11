// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #pragma comment(linker, "/STACK:16777216")
//#pragma GCC target ("avx2,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 998244353ll
using namespace std;
using namespace __gnu_pbds;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
}
template<typename X, typename Y>
istream& operator>>(istream& in, pair<X, Y> &a) {
	in >> a.first >> a.second;
	return in;
}
template<typename T>
void getv(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv(vector<T>& v, int n, Ns ... ns) {
	v.resize(n);
	for (auto& i : v)
		getv(i, ns...);
}
template<typename T>
void getv1(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv1(vector<T>& v, int n, Ns ... ns) {
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
		getv1(v[i], ns...);
}
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
inline void getch(char &x) {
	while (x = getchar_unlocked(), x < 33) {
		;
	}
}
inline void getstr(string &str) {
	str.clear();
	char cur;
	while (cur = getchar_unlocked(), cur < 33) {
		;
	}
	while (cur > 32) {
		str += cur;
		cur = getchar_unlocked();
	}
}
template<typename T> inline bool sc(T &num) {
	bool neg = 0;
	int c;
	num = 0;
	while (c = getchar_unlocked(), c < 33) {
		if (c == EOF)
			return false;
	}
	if (c == '-') {
		neg = 1;
		c = getchar_unlocked();
	}
	for (; c > 47; c = getchar_unlocked())
		num = num * 10 + c - 48;
	if (neg)
		num *= -1;
	return true;
}
template<typename a, typename b>
void minq(a& x, b y) {
	if (x > y)
		x = y;
}
template<typename a, typename b>
void maxq(a& x, b y) {
	if (x < y)
		x = y;
}
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef int _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <string> vs;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;
//store differences, not the elements for rsq in fenwick or array(for write-only)
//Sum Over Subsets + inclusion-exclusion is a thing! (Solved div1E (383E) using it!)
//SQRT-heuristic divide items into groups: >sqrt and <=sqrt and do something according to group(eg. trie for one, z-func for other) - 1202E
uniform_real_distribution<double> double_dist(0, 1);
uniform_int_distribution<int> dist(4, 55);
//WHEN DOING MODULAR SUBTRACTION ALWAYS **ALWAYS** ADD MOD
//don't use AVX at AtCoder(=RE)
//Trie: MAXDEPTH!=MAXSIZE
//suspiciously big numbers? use python, seriosly you don't wanna waste your time if it overflows
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//SQRT IS PROBABLY THE ANSWER
const int MAXN = 4e5 + 333, sigma = 26;

struct fenwick {
	int t[MAXN], n;
	void init(int sz) {
		memset(t, 0, sizeof t);
		n = sz;
	}
	void _update(int p, int val) {
		while(p <= n) {
			t[p] += val;
			p+=p&-p;
		}
	}
	void update(int l, int r, int val) {
		_update(l, val), _update(r+1, -val);
	}
	int get(int p) {
		int res = 0;
		while(p) {
			res += t[p];
			p-=p&-p;
		}
		return res;
	}
};

int term[MAXN], link[MAXN], to[MAXN][sigma], sz;
void init() {
	memset(term, 0, sizeof term);
	memset(link, 0, sizeof link);
	memset(to, 0, sizeof to);
	sz = 1;
}
void add_string(string& s, int i) {
	int cur = 0;
	for(auto c : s) {
		if(!to[cur][c-'a']) to[cur][c-'a'] = sz++;
		cur = to[cur][c-'a'];
	}
	term[i] = cur;
}
void push_links() {
	int q[MAXN], s = 0, e = 1;
	q[0] = 0;
	while(s < e) {
		int v = q[s++];
		int u = link[v];
		for(int i = 0; i < sigma; i++) {
			if(to[v][i]) {
				link[to[v][i]] = v ? to[u][i] : 0;
				q[e++] = to[v][i];
			} else
				to[v][i] = to[u][i];
		}
	}
}

int n, m, link_euler_timer, link_topo_timer;
vector<vector<pair<int, char>>> song_tree;
vector<vector<int>> song_queries, link_tree;
vector<int> query_ans, link_euler_in, link_euler_out, link_topo_in, link_topo_out;
fenwick link_euler_fenwick, link_topo_fenwick;

void dfs_link(int v = 0) {
	link_euler_in[v] = link_euler_timer++;
	link_topo_in[v] = link_topo_timer;
	for(auto i : link_tree[v]) {
		dfs_link(i);
	}
	link_topo_out[v] = link_topo_timer++;
	link_euler_out[v] = link_euler_timer;
}

void build_link_tree() {
	link_tree.resize(sz);
	for(int i = 1; i < sz; i++)
		link_tree[link[i]].pb(i);
	link_euler_fenwick.init(sz);
	link_topo_fenwick.init(sz);
	link_euler_in.resize(sz);
	link_euler_out.resize(sz);
	link_topo_in.resize(sz);
	link_topo_out.resize(sz);
	link_euler_timer = 1;
	link_topo_timer = 1;
	dfs_link();
}

void v_to_root_add(int v, int val) {
	link_topo_fenwick.update(link_topo_in[v], sz, val);
	link_euler_fenwick.update(link_euler_in[v]+1, sz, -val);
}
int v_get(int v) {
	int val = link_euler_fenwick.get(link_euler_in[v]);
	val += link_topo_fenwick.get(link_topo_out[v]);
	return val;
}

void dfs_song(int v = 0, int cur = 0) {
	v_to_root_add(cur, 1);
	for(auto i : song_queries[v]) {
		query_ans[i] = v_get(term[i]);
	}
	for(auto i : song_tree[v]) {
		dfs_song(i.first, to[cur][i.second-'a']);
	}
	v_to_root_add(cur, -1);
}

int main() {
	doin();
	cin >> n;
	song_tree.resize(n+1);
	int t, p;
	char c;
	for(int i = 1; i <= n; i++) {
		cin >> t;
		if(t == 1) p = 0, cin >> c;
		else cin >> p >> c;
		song_tree[p].pb({i, c});
	}

	init();
	song_queries.resize(n+1);
	cin >> m;
	int j;
	string T;
	for(int i = 0; i < m; i++) {
		cin >> j >> T;
		song_queries[j].pb(i);
		add_string(T, i);
	}
	push_links();
	build_link_tree();
	query_ans.resize(m);
	dfs_song();
	for(auto i : query_ans)
		cout << i << "\n";
}