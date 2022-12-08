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
const double eps = 1e-7;
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

ll foo(ll x) {
	return x * (x + 1) / 2;
}

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < (n + 1) / 2; i++) {
		cin >> a[i];
	}
	int m = (n + 1) / 2;
	ll x; cin >> x;
	for (int i = (n + 1) / 2; i < n; i++)
		a[i] = x;
	if (x >= 0) {
		ll s = 0;
		for (ll i : a)
			s += i;
		if (s > 0) cout << n << endl;
		else cout << -1 << endl;
	}
	else {
		vector<ll> p(n + 1);
		p[0] = 0;
		for (int i = 1; i <= n; i++)
			p[i] = p[i - 1] + a[i - 1];
		int mini = n + 1;
		int m = (n / 2) + 1;
		for (int i = 0; i <= n - m; i++) {
			int l = m, r = n - i + 1;
			//cout << p[i + m] - p[i] << " " << i << " " << p[i] << " " << p[i + m] << " " << m <<  endl;
			if (p[i + m] - p[i] <= 0) mini = min(mini, m);
			else {
				while (r - l > 1) {
					int mid = l + r >> 1;
					if (p[i + mid] - p[i] > 0)l = mid;
					else r = mid;
				}
				if (l != n) mini = min(mini, l + 1);
			}
			//cout << mini << endl;
			if ((n - i) < mini) {
				cout << n - i << endl;
				return;
			}
		}
		cout << -1 << endl;
	}
	return;
}