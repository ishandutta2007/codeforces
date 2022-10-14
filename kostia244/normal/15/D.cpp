#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
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
typedef int _I;
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
ll n, m, a, b, x, y, z, g, mat[1011][1011], best[1011][1011], sum[1011][1011];
deque<ll> Q;
bitset<1011> vis[1011];
struct v {
	int x, y;
	ll val;
	bool operator<(const v& o) const {
		return val > o.val || (val == o.val && x > o.x)
				|| (val == o.val && x == o.x && y > o.y);
	}
};
inline void nxt(ll& a) {
	a = (((a * x) % z) + y) % z;
}
inline void push(ll x) {
	while (!Q.empty() && Q.back() > x)
		Q.pop_back();
	Q.push_back(x);
}
int main() {
	doin();
	cin >> n >> m >> a >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i].set(j);
			cin >> mat[i][j];
			sum[i][j] = mat[i][j] + (i ? sum[i - 1][j] : 0)
					+ (j ? sum[i][j - 1] : 0)
					- (i && j ? sum[i - 1][j - 1] : 0);
		}
	}

	for (int i = 0; i < n; i++) {
		Q.clear();
		for (int j = 0; j < m; j++) {
			push(mat[i][j]);
			if (j >= b - 1) {
				best[i][j] = Q.front();
				if (Q.front() == mat[i][j - b + 1])
					Q.pop_front();
			}
		}
	}
	priority_queue<v> qq;
	for (int j = b - 1; j < m; j++) {
		Q.clear();
		for (int i = 0; i < n; i++) {
			push(best[i][j]);
			if (i >= a - 1) {
				qq.push(
						{ i, j, (sum[i][j] - (j - b >= 0 ? sum[i][j - b] : 0)
								- (i - a >= 0 ? sum[i - a][j] : 0)
								+ (i - a >= 0 && j - b >= 0 ?
										sum[i - a][j - b] : 0)
								- a * b * Q.front()) });
				if (Q.front() == best[i - a + 1][j])
					Q.pop_front();
			}
		}
	}
	vector<pair<pi, ll>> rr;
	while (!qq.empty()) {
		v t = qq.top();
		qq.pop();
		if (!vis[t.x].test(t.y))
			continue;
		rr.pb( { { t.x - a + 2, t.y - b + 2 }, t.val });
		int lx = max(0ll, t.x - (a - 1)), rx = min(n, t.x + a - 1);
		int ly = max(0ll, t.y - (b - 1)), ry = min(m, t.y + b - 1);
		for (; lx <= rx; lx++) {
			int i;
			if (ly == 0) {
				i = (vis[lx].test(0) ? 0 : vis[lx]._Find_next(0));
			} else {
				i = vis[lx]._Find_next(ly - 1);
			}
			while (i <= ry) {
				vis[lx].set(i, 0);
				i = vis[lx]._Find_next(i);
			}
		}
	}
	cout << rr.size() << "\n";
	for (auto i : rr)
		cout << i.first.first << " " << i.first.second << " " << i.second
				<< "\n";
	return 0;
}