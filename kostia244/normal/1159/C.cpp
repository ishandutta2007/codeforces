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
ll n, m, ans = 0, t, mn = INT_MAX, mx = INT_MIN;
vi b, g, sumb, sumg;
int main() {
	doin();
	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin >> t;
//		mx = max(t, mx);
//		if (t)
//			b.pb(t);
//	}
//	for (int i = 0; i < m; i++) {
//		cin >> t;
//		mn = min(t, mn);
//		if (t)
//			g.pb(t);
//	}
//	n = b.size();
//	m = g.size();
	getv(b, n);
	getv(g, m);
	if (*max_element(all(b)) > *min_element(all(g)))
		return cout << -1, 0;
	sort(all(b));
	sort(all(g));
	sumb.resize(n);
	partial_sum(all(b), sumb.begin());
	sumg.resize(m);
	partial_sum(all(g), sumg.begin());
	if(n == 0) {
		cout << sumg.back();
		return 0;
	}
//	if(n)
		ans += sumg.back() - sumg[0] + b.back();
//	if (n > 1) {
		ans += b[n - 2] * (m - 1);
		ans += sumg[0];
//	}
	if(find(g.begin(), g.end(), b.back()) != g.end())
	ans = min(ans, sumg.back()+m*b[n-2]);
	for (int i = 0; i + 2 < n; i++)
		ans += m * b[i];
	cout << ans;
}