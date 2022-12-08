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

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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

ll get(ll x, ll t) {
	ll y = x + t;
	if (y >= 0)
		return (y + 1) / 2;
	else
		return y / 2;
}

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	vector<ll> b(n - 1);
	ll t = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i) {
			b[i - 1] = a[i] - a[i - 1];
			if (b[i - 1] > 0)
				t += b[i - 1];
		}
	}
	cout << get(a[0], t) << endl;
	int q; cin >> q;
	while (q--) {
		int l, r, x; cin >> l >> r >> x; l--; r--;
		if (!l) {
			a[0] += x;
		}
		else {
			if (b[l - 1] > 0)
				t -= b[l - 1];
			b[l - 1] += x;
			if (b[l - 1] > 0)
				t += b[l - 1];
		}
		if (r != (n - 1)) {
			if (b[r] > 0)
				t -= b[r];
			b[r] -= x;
			if (b[r] > 0)
				t += b[r];
		}
		cout << get(a[0], t) << endl;
	}
	return;
}