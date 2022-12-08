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

ll add(ll a, ll b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

ll mul(ll a, ll b) {
	return a * b % mod;	
}

ll bp(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		k >>= 1;
	}
	return res;
}

ll rev(ll a) {
	return bp(a, mod - 2);
}

void solve(){
	int n; cin >> n;
	vector<ll> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(rall(c));
	vector<ll> pref(n);
	pref[0] = c[0];
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + c[i];
	}
	for (int k = 1; k <= n; k++) {
		ll ans = 0;
		for (int j = k; j < n; j += k) {
			int l = j, r = min(n - 1, j + k - 1);
			ans = add(ans, mul((j / k), (pref[r] - pref[l - 1])));
		}
		cout << mul(ans, rev(n)) << " ";
	}
	return;
}