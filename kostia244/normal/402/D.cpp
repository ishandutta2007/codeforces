#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
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
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
unordered_map<int, int> dp;
vi a, b;

int f(int x) {
	if (x == 1)
		return 0;
	if (x == 0)
		return 0;
	if (dp.find(x) != dp.end())
		return dp[x];
	int X = x;
	int ans = 0;
	for (ll i = 0; b[i] <= x && i < m; i++) {
		while (x % b[i] == 0) {
			x /= b[i], ans--;
		}
	}
	for (ll i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			x /= i, ans++;
		}
	}
	if (x > 1)
		ans++;
	return dp[X] = ans;
}

int main() {
	doin();
	cin >> n >> m;
	getv(a, n);
	getv(b, m);
	int ans = 0, bi, tg, ub = n, g, og;
	while (1) {
		g = 0;
		bi = -1;
		ans = 0;
		for (int i = 0; i < ub; i++) {
			og = g;
			g = __gcd(g, a[i]);
			if (og)
				ans -= f(og / g);
			else
				ans = f(g);
			if (ans < 0)
				bi = i, tg = g;
		}
		if (bi == -1)
			break;
		ub = bi;
		for (int i = 0; i <= ub; i++)
			a[i] /= tg;
	}
	ans = 0;
	for (int i = 0; i < n; i++) {
		ans += f(a[i]);
	}
	cout << ans;
}