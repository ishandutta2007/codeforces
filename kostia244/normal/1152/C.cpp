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
#define mod 1234567891ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//		freopen("in", "r", stdin);
//		freopen("out", "w", stdout);
#endif
}
template<typename T, typename l>
void getv(T& a, int n, l f) {
	a.resize(n);
	for (auto& i : a)
		cin >> i, f(i);
}
template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
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
ll a, b, t, td, ak = 0, k, ans;
int main() {
	doin();
	cin >> a >> b;
	if (a < b)
		swap(a, b);
	ans = (a * b)/__gcd(a, b);
	t = a - b;
	for (ll d = 1; d * d <= t; d++) {
		if (t % d)
			continue;
		k = d - (b % d);
		if (ans > ((a + k) * (b + k) / __gcd(a + k, b + k)))
			ak = k, ans = ((a + k) * (b + k) / __gcd(a + k, b + k));
		td = (t/d);
		k = td - (b % td);
		if (ans > ((a + k) * (b + k) / __gcd(a + k, b + k)))
			ak = k, ans = ((a + k) * (b + k) / __gcd(a + k, b + k));
	}
	cout << ak;
}