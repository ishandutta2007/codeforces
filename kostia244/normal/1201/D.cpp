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
int main() {
	doin();
	const long long INF = 100000000000000000LL;
	ll n, m, k, q, dp[200100][2];
	set<ll> good;
	map<ll, pi> cnt;
	cin >> n >> m >> k >> q;
	for (ll r, c, i = 0; i < k; i++) {
		cin >> r >> c;
		if (cnt.find(r) == cnt.end())
			cnt[r] = {INF, -INF};
		cnt[r].first = min(cnt[r].first, c);
		cnt[r].second = max(cnt[r].second, c);
	}
	for (int t, i = 0; i < q; i++)
		cin >> t, good.insert(t);
	if (cnt.find(1) == cnt.end())
		cnt[1] = {INF, -INF};
	cnt[1].first = min(cnt[1].first, 1ll);
	cnt[1].second = max(cnt[1].second, 1ll);
	vector<pair<ll, pi>> u;
	u.pb( { -1, { -1, -1 } });
	for (auto i : cnt)
		u.pb( { i.first, i.second }); //, cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
	sort(all(u));

	for (int i = 1; i <= n; i++)
		dp[i][0] = dp[i][1] = INF;
	dp[1][0] = 0;
	dp[1][1] = u[1].second.second - 1;
	for (int i = 1; i + 1 < u.size(); i++) {
//		dp[i][0] = min(dp[i][0], dp[i][1]);
//		dp[i][1] = min(dp[i][1], dp[i][0]);
		auto it = good.upper_bound(u[i].second.first);
		auto lit = it, rit = it;
		if (it != good.begin()) {
			lit--;
		}
		if (it == good.end()) {
			rit--;
		}
		it = good.upper_bound(u[i].second.second);
		auto lit1 = it, rit1 = it;
		if (it != good.begin()) {
			lit1--;
		}
		if (it == good.end()) {
			rit1--;
		}
//		cout << u[i].second.first << " " << u[i].second.second << "\n";
//		continue;
		for (auto l : { lit, rit, lit1, rit1 }) {
			ll DLME = abs(*l - u[i].second.first);
			ll DRME = abs(*l - u[i].second.second);
			ll DL = abs(*l - u[i + 1].second.first);
			ll DR = abs(*l - u[i + 1].second.second);
			ll Hd = u[i + 1].first - u[i].first;
			ll sweep = (u[i].second.second - u[i].second.first);
//			cout << *l << "\n"; // << u[i].second.first << " -> " << u
			dp[i + 1][0] = min(dp[i + 1][0],
					min(dp[i][1] + sweep, dp[i][0] + 2 * sweep) + DLME + Hd
							+ DL);
			dp[i + 1][0] = min(dp[i + 1][0],
					min(dp[i][0] + sweep, dp[i][1] + 2 * sweep) + DRME + Hd
							+ DL);

			dp[i + 1][1] = min(dp[i + 1][1],
					min(dp[i][1] + sweep, dp[i][0] + 2 * sweep) + DLME + Hd
							+ DR);
			dp[i + 1][1] = min(dp[i + 1][1],
					min(dp[i][0] + sweep, dp[i][1] + 2 * sweep) + DRME + Hd
							+ DR);
		}
//		cout << "(" << dp[i][0] << " " << dp[i][1] << ")\n";
	}
//	cout << u.back().second.first << " " << u.back().second.second << "\n";
//	dp[n][0] = min(dp[n][0], dp[n][1] + m - 1);
//	dp[n][1] = min(dp[n][1], dp[n][0] + m - 1);
//	cout << dp[u.size() - 1][0] << " " << dp[u.size() - 1][1] << "\n";
	cout
			<< min(dp[u.size() - 1][0], dp[u.size() - 1][1])
					+ cnt[u.back().first].second - cnt[u.back().first].first;
}