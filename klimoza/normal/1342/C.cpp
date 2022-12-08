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

const int N = 201;

int kek[N][N];

int gcd(int a, int b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

ll get(ll p, ll x, ll b) {
	ll t = p / x * x;
	ll ans = t / x * b + min(b, p - t + 1);
	return ans;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		ll t = lcm(a, b);
		int q; cin >> q;
		while (q--) {
			ll l, r;
			cin >> l >> r;
			ll ans = get(r, t, b) - get(l - 1, t, b);
			cout << (r - l + 1) - ans << " ";
		}
		cout << endl;
	}
	return;
}