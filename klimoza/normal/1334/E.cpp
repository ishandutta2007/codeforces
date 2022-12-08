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

mt19937 mrand(43);

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

ll gcd(ll a, ll b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

ll mul(ll a, ll b) {
	return a * b % mod;
}

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

const int L = 60;

ll fac[L], rev[L];

void build() {
	fac[0] = 1;
	for (int i = 1; i < L; i++) {
		fac[i] = fac[i - 1] * 1ll * i % mod;
	}
	rev[L - 1] = bp(fac[L - 1], mod - 2);
	for (int i = L - 2; i >= 0; i--) {
		rev[i] = rev[i + 1] * 1ll * (i + 1) % mod;
	}
}

void solve() {
	build();
	ll d; cin >> d;
	vector<ll> p;
	ll x = d;
	for (ll i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			p.push_back(i);
			while (x % i == 0)
				x /= i;
		}
	}
	if (x != 1)
		p.push_back(x);
	int q; cin >> q;
	while (q--) {
		ll x, y;
		cin >> x >> y;
		ll g = gcd(x, y);
		ll t1 = x / g;
		ll t2 = y / g;
		ll a1 = 0;
		ll a2 = 0;
		vector<int> p1, p2;
		for (ll i : p) {
			if (t1 % i == 0) {
				int cnt = 0;
				while (t1 % i == 0) {
					t1 /= i;
					cnt++;
				}
				p1.push_back(cnt);
			}
			if (t2 % i == 0) {
				int cnt = 0;
				while (t2 % i == 0) {
					t2 /= i;
					cnt++;
				}
				p2.push_back(cnt);
			}
		}
		for (int i : p1)
			a1 += i;
		a1 = fac[a1];
		for (int i : p1)
			a1 = mul(a1, rev[i]);
		for (int i : p2)
			a2 += i;
		a2 = fac[a2];
		for (int i : p2)
			a2 = mul(a2, rev[i]);
		a1 = mul(a1, a2);
		cout << a1 << endl;
	}
	return;
}