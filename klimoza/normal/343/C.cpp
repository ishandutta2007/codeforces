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

void solve() {
	int n, t; cin >> n >> t;
	vector<ll> h(n);
	for (ll& i : h)
		cin >> i;
	vector<ll> p(t);
	for (ll& i : p)
		cin >> i;
	ll l = -1, r = 2e10;
	while (r - l > 1) {
		ll m = l + r >> 1;
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (cur == t) break;
			ll k = m;
			if (p[cur] >= h[i]) {
				while (cur < t && (p[cur] - h[i]) <= k)
					cur++;
			}
			else {
				int id = cur;
				ll tmp = k;
				if (h[i] - p[id] > k) break;
				k -= 2 * (h[i] - p[id]);
				while (id < t && h[i] >= p[id])
					id++;
				while (id < t && (p[id] - h[i]) <= k)
					id++;
				k = tmp - (h[i] - p[cur]);
				while (cur < t && h[i] >= p[cur])
					cur++;
				while (cur < t && 2 * (p[cur] - h[i]) <= k)
					cur++;
				cur = max(cur, id);
			}
		}
		if (cur == t) r = m;
		else l = m;
	}
	cout << r << endl;
	return;
}