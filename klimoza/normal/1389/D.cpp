/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(239);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

ll intersect(ll a, ll b, ll x, ll y) {
	a = max(a, x);
	b = min(b, y);
	return max(b - a, 0ll);
}

void solve() {
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		ll l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		k -= n * intersect(l1, r1, l2, r2);
		if (k <= 0) cout << 0 << endl;
		else {
			ll ans = 4e18;
			ll tp = 0;
			for (int i = 1; i <= n; i++) {
				ll cur = 0;
				ll cc = 0;
				if (intersect(l1, r1, l2, r2) || (max(r1, r2) == min(l1, l2))) {
					ll mem = max(r2, r1) - min(r2, r1) + max(l1, l2) - min(l1, l2);
					cc += min(mem, k);
					cur += min(mem, k);
				}
				else {
					ll mem = max(r2, r1) - min(l1, l2);
					cur += max(l1, l2) - min(r1, r2) + min(mem, k);
					cc += min(mem, k);
				}
				ans = min(ans, cur + 2 * (k - cc) + tp);
				tp += cur;
				k -= cc;
			}
			cout << ans << endl;
		}
	}
	return;
}