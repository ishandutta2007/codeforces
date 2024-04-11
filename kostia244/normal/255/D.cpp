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
istream& operator>>(istream& in, pair<X, Y> a) {
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, c, x, y;

void sub(ll& a, ll b) {
	if (b > 0)
		a -= b * b;
}
void add(ll& a, ll b, ll c) {
	if(b-c-1<=0) return;
	b = b-c-1;
	a += (b * (b + 1)) / 2;
}

ll val(ll m) {
	ll ans = m * m + (m + 1LL) * (m + 1LL);
	ll lx = x - 1, rx = n - x;
	ll ly = y - 1, ry = n - y;
	sub(ans, m - lx);
	sub(ans, m - rx);
	sub(ans, m - ly);
	sub(ans, m - ry);
	add(ans, m - lx, ly);
	add(ans, m - lx, ry);
	add(ans, m - rx, ly);
	add(ans, m - rx, ry);
	return ans;
}

int main() {
	doin();
	cin >> n >> x >> y >> c;
	ll lo = 0, hi = 1000000, mid, t;
	while (lo < hi) {
		mid = (lo + hi) >> 1;
		if (val(mid) >= c) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	cout << fixed << hi;
}