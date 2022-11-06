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
const int N = 1000000;

int a[N], mxlen[N];
ll mxval[N];

pair<int, ll> brute(int depth, ll m) {
	if (depth == 0) {
		assert(m < N);
		return {mxlen[m], mxval[m]};
	}
	pair<int, ll> ans = {0, 0};
	int t = pow(m, 1.0 / 3) + eps;
	for (ll i = max(1, t - 200); i <= t; ++i) {
		ll m1 = min(m - i * i * i, 3 * i * (i + 1));
		pair<int, ll> tmp = brute(depth - 1, m1);
		ans = max(ans, {tmp.fs + 1, tmp.sn + i * i * i});
	}
	return ans;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	a[0] = 0;
	ll t = 1;	
	forn(i, 1, N) {
		ll cb = t * t * t;
		if (cb + 3 * t * (t + 1) == i) ++t;
		a[i] = a[i - cb] + 1;
	}
	mxlen[0] = 0, mxval[0] = 0;
	forn(i, 1, N) {
		if (a[i] >= mxlen[i - 1]) {
			mxlen[i] = a[i];
			mxval[i] = i;
		} else {
			mxlen[i] = mxlen[i - 1];
			mxval[i] = mxval[i - 1];
		}
	}
	ll m;
	cin >> m;
	pair<int, ll> ans = brute(3, m);
	cout << ans.fs << ' ' << ans.sn << '\n';
	return 0;
}