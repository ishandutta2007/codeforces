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

const int N = 2e5 + 7;
int n, k;
ll a[N], b[N];
ll u[N];

bool check(ll x) {
	fill(u, u + N, 0);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		ll cur = 0;
		ll tmp = a[i];
		while (true) {
			ll mem = tmp / b[i] + 1;
			tmp -= mem * b[i];
			cur += mem;
			//cout << cur << " " << mem << endl;
			if (cur >= k) break;
			if (!x) return false;
			mem = (abs(tmp) + x - 1) / x;
			cnt += mem;
			tmp += mem * x;
			//cout << tmp << " " << cnt << endl;
			if (cnt >= k) return false;
			u[cur] += mem;
		}
	}
	ll cc = 0;
	for (int i = 1; i < k; i++) {
		cc += u[i];
		if (cc > i) return false;
	}
	return true;
}

const ll R = 1e13;

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	ll l = -1, r = R;
	while (r - l > 1) {
		ll m = l + r >> 1;
		//cout << m << endl;
		if (check(m)) r = m;
		else l = m;
	}
	if (!check(r)) cout << -1 << endl;
	else cout << r << endl;
	return;
}