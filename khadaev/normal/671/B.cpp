#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> c(n);
	forn(i, 0, n) cin >> c[i];
	sort(all(c));
	ll cur = 0, mx = -1;
	ford(i, 1, n) {
		if (cur + (c[i] - c[i - 1]) * (n - i) <= k) {
			cur += (c[i] - c[i - 1]) * (n - i);
			//cerr << cur << '\n';
		} else {
			mx = c[i] - (k - cur) / (n - i);
			//cerr << i << ' ' << mx << '\n';
			break;
		}
	}
	cur = 0;
	ll mn = INF;
	forn(i, 0, n - 1) {
		if (cur + (c[i + 1] - c[i]) * (i + 1) <= k) {
			cur += (c[i + 1] - c[i]) * (i + 1);
			//cerr << cur << '\n';
		} else {
			mn = c[i] + (k - cur) / (i + 1);
			//cerr << i << ' ' << mn << '\n';
			break;
		}
	}
	ll s = 0;
	forn(i, 0, n) s += c[i];
	ll midl = s / n;
	ll midr = midl;
	if (s % n) ++midr;
	mn = min(mn, midl);
	mx = max(mx, midr);
	cout << mx - mn << '\n';
	return 0;
}