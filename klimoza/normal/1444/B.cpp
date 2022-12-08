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
//mt19937 mrand(228);

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

const int N = 3e5 + 2;

ll fac[N], rev[N];

ll bp(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1)
			res = res * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return res;
}

void build() {
	fac[0] = 1;
	for (int i = 1; i < N; i++)
		fac[i] = fac[i - 1] * i % mod;
	rev[N - 1] = bp(fac[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; i--) {
		rev[i] = rev[i + 1] * (i + 1) % mod;
	}
}

ll mul(ll a, ll b) {
	return a * b % mod;
}

ll C(ll n, ll k) {
	return mul(fac[n], mul(rev[k], rev[n - k]));
}

void solve() {
	build();
	int n; cin >> n;
	vector<int> a(2 * n);
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i];
	sort(all(a));
	ll s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++) {
		s1 += a[i];
		s2 += a[i + n];
	}
	cout << mul((s2 - s1) % mod, C(2 * n, n)) << endl;
	return;
}