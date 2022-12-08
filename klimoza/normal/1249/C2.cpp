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

double PI = acos((double)-1);
const ld eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
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

ll bp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1)
			res = res * a;
		a *= a;
		b >>= 1;
	}
	return res;
}

void solve() {
	int q; cin >> q;
	while (q--) {
		ll n; cin >> n;
		ll kek = 3;
		int c = 1;
		while (3 * kek <= 3e18) {
			kek *= 3;
			c++;
		}
		vector<int> mem(60, 0);
		ll x = n;
		while (kek) {
			mem[c] = x / kek;
			x = x % kek;
			kek /= 3;
			c--;
		}
		int t = -1;
		for (int i = 0; i < 60; i++) {
			if (mem[i] == 2)
				t = i;
		}
		if (t == -1) {
			cout << n << endl;
			continue;
		}
		int j = 0;
		for (int i = t + 1; i < 60; i++) {
			if (mem[i] == 0) {
				j = i;
				break;
			}
		}
		ll ans = bp(3ll, j);
		for (int i = j + 1; i < 60; i++) {
			if (!mem[i]) continue;
			ans += bp(3ll, i);
		}
		cout << ans << endl;
	}
	return;
}