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
#define mod 1000000007ll
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
template<typename T, typename ... Ns>
void getv1(vector<T>& v, int n, Ns ... ns) {
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
		getv(v[i], ns...);
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

pi f[800100];
vpi dp;
struct segtree {
	int n;
	void init(int n) {
		dp.assign(n + 1, { 0, 0 });
		this->n = n;
		for (int i = 0; i < 4 * n + 5; i++)
			f[i] = {LLONG_MAX, 0};
		}
		pi merge(pi a, pi b) {
			if(a > b)
			swap(a, b);
			if(a.first == b.first) a.second += b.second;
			a.second %= mod;
			return a;
		}
		pi get(int v, int l, int r, int qL, int qR) {
			if(l > qR || r < qL)
			return {LLONG_MAX, 0};
			if(l >= qL && r <= qR) {
				return f[v];
			}
			int mid = (l + r)/2;
			return merge(get(2*v, l, mid, qL, qR), get(2*v + 1, mid+ 1, r, qL, qR));
		}
		void upd(int v, int i, pi val, int l, int r) {
			if(l == r) {
				f[v] = val;
				return;
			}
			int mid = (l + r) / 2;
			if(i <= mid) {
				upd(2*v, i, val, l, mid);
			} else {
				upd(2*v + 1, i, val, mid+1, r);
			}
			f[v] = merge(f[2*v], f[2*v+1]);
		}
		void upd(int i, pi val) {
			dp[i] = val;
			upd(1, i, val, 1, n);
		}
		pi get(int l, int r) {
			return get(1, 1, n, l, r);
		}
	};

int main() {
	doin();
	int n;
	vpi a;
	cin >> n;
	getv(a, n);
	for (auto& i : a)
		swap(i.first, i.second);
	sort(all(a));
	segtree st;
	st.init(n);
	int j = n + 1;
	ll mn = LLONG_MAX;
	for (int i = n; i; i--) {
		auto it = lower_bound(all(a), pi(a[i - 1].second, 0ll));
		if (it == a.end()) {
			st.upd(i, { a[i - 1].first, 1 });
			mn = min(mn, dp[i].first);
			continue;
		}
		j = it - a.begin() + 1;
		dp[i] = st.get(j, n);
		dp[i].first -= a[i - 1].second - a[i - 1].first;
		mn = min(mn, dp[i].first);
		st.upd(i, dp[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (dp[i].first == mn) {
			ans += dp[i].second;
			ans %= mod;
		}
	cout << ans;
	return 0;
}