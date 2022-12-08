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

const int N = 2e5 + 8;

pair<int, int> used[N];
int sz[N];

ll gcd(ll a, ll b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

void relax(pair<int, int>& v, int a) {
	if (v.first >= a) {
		v.second = v.first;
		v.first = a;
	}
	else if (v.second >= a) {
		v.second = a;
	}
}

ll bp(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1)
			res = res * a;
		a = a * a;
		k >>= 1;
	}
	return res;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	fill(used, used + N, mp(inf0, inf0));
	fill(sz, sz + N, 0);
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		vector<pair<int, int>> kek;
		for (int j = 2; j <= sqrt(a[i]); j++) {
			if (a[i] % j) continue;
			sz[j]++;
			kek.push_back(mp(j, 0));
			while (a[i] % j == 0) {
				kek.back().second++;
				a[i] /= j;
			}
		}
		if (a[i] > 1) {
			kek.push_back({ a[i], 1 });
			sz[a[i]]++;
		}
		for (auto u : kek) {
			relax(used[u.first], u.second);
		}
	}
	for (int i = 2; i < N; i++) {
		//cout << i << " " << used[i].first << " " << used[i].second << endl;
		if (sz[i] < (n - 1)) continue;
		else if (sz[i] == n - 1) ans *= bp(i, used[i].first);
		else ans *= bp(i, used[i].second);
	}
	cout << ans << endl;
	return;
}