//#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.begin(), x.end()
#define oit ostream_iterator
#define mod 998244353ll
using namespace std;
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
//template<typename T, typename ... Ns>
//void getv1(vector<T>& v, int n, Ns ... ns) {
//	v.resize(n + 1);
//	for (ll i = 1; i <= n; i++)
//		getv(v[i], ns...);
//}
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
//template<typename T> inline bool sc(T &num) {
//	bool neg = 0;
//	ll c;
//	num = 0;
//	while (c = getchar_unlocked(), c < 33) {
//		if (c == EOF)
//			return false;
//	}
//	if (c == '-') {
//		neg = 1;
//		c = getchar_unlocked();
//	}
//	for (; c > 47; c = getchar_unlocked())
//		num = num * 10 + c - 48;
//	if (neg)
//		num *= -1;
//	return true;
//}
typedef unsigned long long ull;
typedef long long ll;
typedef float ld;
typedef ll _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;
uniform_real_distribution<double> double_dist(0, 1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = LLONG_MAX;
struct info {
	ll mx1, mx2, mx_cnt, mn1, mn2, mn_cnt;

	info(ll a = -INF, ll b = -INF, ll c = 0, ll d = INF, ll e = INF, ll f = 0) {
		mx1 = a, mx2 = b, mx_cnt = c, mn1 = d, mn2 = e, mn_cnt = f;
	}
	friend inline info merge(info u, info v) {
		if (u.mx1 < v.mx1) {
			u.mx_cnt = 0;
			u.mx2 = u.mx1;
			u.mx1 = v.mx1;
		}
		if (u.mx1 == v.mx1) {
			u.mx_cnt += v.mx_cnt;
			u.mx2 = max(u.mx2, v.mx2);
		}
		else
			u.mx2 = max(u.mx2, v.mx1);
		if (u.mn1 > v.mn1) {
			u.mn_cnt = 0;
			u.mn2 = u.mn1;
			u.mn1 = v.mn1;
		}
		if (u.mn1 == v.mn1) {
			u.mn_cnt += v.mn_cnt;
			u.mn2 = min(u.mn2, v.mn2);
		}
		else
			u.mn2 = min(u.mn2, v.mn1);
		return u;
	}
};
struct node {
	info p;
	long long sum;
	ll mx_lazy, mn_lazy;

	node(info a = info(), long long b = 0) {
		p = a, sum = b, reset();
	}
	inline void reset() {
		mx_lazy = -INF, mn_lazy = INF;
	}
	inline void set_max(ll x) {
		if (x <= p.mn1)
			return;
		sum += 1LL * (x - p.mn1) * p.mn_cnt;
		if (p.mx1 == p.mn1)
			p.mx1 = x;
		if (p.mx2 == p.mn1)
			p.mx2 = x;
		p.mn1 = mx_lazy = x;
	}
	inline void set_min(ll x) {
		if (x >= p.mx1)
			return;
		sum += 1LL * (x - p.mx1) * p.mx_cnt;
		if (p.mn1 == p.mx1)
			p.mn1 = x;
		if (p.mn2 == p.mx1)
			p.mn2 = x;
		p.mx1 = mn_lazy = x;
	}
	friend inline node merge(node u, node v) {
		u.p = merge(u.p, v.p);
		u.sum += v.sum;
		u.reset();
		return u;
	}
};

const ll N = 2e5;
node seg[N << 2];
ll n, q, a[N];

inline void find(ll id) {
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

inline void shift(ll id) {
	for (auto p: {id << 1, id << 1 | 1}) {
		seg[p].set_max(seg[id].mx_lazy);
		seg[p].set_min(seg[id].mn_lazy);
	}
	seg[id].reset();
}

void build(ll id = 1, ll st = 0, ll en = n) {
	if (en - st == 1) {
		info x;
		x.mx1 = a[st], x.mx_cnt = 1;
		x.mn1 = a[st], x.mn_cnt = 1;
		seg[id] = {x, a[st]};
		return;
	}
	ll mid = st + en >> 1;
	build(id << 1, st, mid);
	build(id << 1 | 1, mid, en);
	find(id);
}

void update_max(ll l, ll r, ll x, ll id = 1, ll st = 0, ll en = n) {
	if (r <= st || en <= l || seg[id].p.mn1 >= x)
		return;
	if (l <= st && en <= r && seg[id].p.mn2 > x)
		return seg[id].set_max(x);
	shift(id);
	ll mid = st + en >> 1;
	update_max(l, r, x, id << 1, st, mid);
	update_max(l, r, x, id << 1 | 1, mid, en);
	find(id);
}

void update_min(ll l, ll r, ll x, ll id = 1, ll st = 0, ll en = n) {
	if (r <= st || en <= l || seg[id].p.mx1 <= x)
		return;
	if (l <= st && en <= r && seg[id].p.mx2 < x)
		return seg[id].set_min(x);
	shift(id);
	ll mid = st + en >> 1;
	update_min(l, r, x, id << 1, st, mid);
	update_min(l, r, x, id << 1 | 1, mid, en);
	find(id);
}

long long get(ll l, ll r, ll id = 1, ll st = 0, ll en = n) {
	if (r <= st || en <= l)
		return 0;
	if (l <= st && en <= r)
		return seg[id].sum;
	shift(id);
	ll mid = st + en >> 1;
	return get(l, r, id << 1, st, mid) + get(l, r, id << 1 | 1, mid, en);
}

inline void read_input() {
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
}

inline void write_output() {
	cin >> q;
	for (build(); q--; ) {
		ll t;
		cin >> t;
		if (t == 2) {
			ll l, r, x;
			cin >>  x;
			update_max(0, n, x);
		}
		if (t == 1) {
			ll p, x;
			cin >> p >> x, p--;
			update_min(p, p+1, x);
			update_max(p, p+1, x);
		}
	}
	for(int i = 0; i < n; i++)
	cout << get(i, i+1) << " ";
}


int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read_input(), write_output();
	return 0;
}