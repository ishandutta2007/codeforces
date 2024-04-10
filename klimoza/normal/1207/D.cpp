#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <complex>

#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 998244353;
void solve();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int N = 3e5 + 7;

ll fac[N];

ll build(ll n) {
	if (n == 0) return fac[n] = 1;
	return fac[n] = (n * build(n - 1)) % mod;
}

void solve() {
	int n;
	cin >> n;
	build(n);
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(all(a), [](pair<int, int> x, pair<int, int> y) {
		if (x.first == y.first) return x.second < y.second;
		return x.first < y.first;
	});
	ll ans = fac[n];
	ll cp = 1;
	ll cur = 1;
	bool fl = true;
	for (int i = 1; i < n; i++) {
		if (a[i].second < a[i - 1].second) {
			fl = false;
			break;
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i].first == a[i - 1].first) cur++;
		else {
			cp *= fac[cur];
			cp %= mod;
			cur = 1;
		}
	}
	cp *= fac[cur];
	cp %= mod;
	ans -= cp;
	ans = (ans + mod) % mod;
	if (fl) {
		cp = 1;
		cur = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i - 1]) cur++;
			else {
				cp *= fac[cur];
				cp %= mod;
				cur = 1;
			}
		}
		cp *= fac[cur];
		cp %= mod;
		ans += cp;
		ans %= mod;
	}
	sort(all(a), [](pair<int, int> x, pair<int, int> y) {
		if (x.second == y.second) return x.first < y.first;
		return x.second < y.second;
	});
	 cp = 1;
	 cur = 1;
	for (int i = 1; i < n; i++) {
		if (a[i].second == a[i - 1].second) cur++;
		else {
			cp *= fac[cur];
			cp %= mod;
			cur = 1;
		}
	}
	cp *= fac[cur];
	cp %= mod;
	ans -= cp;
	ans = (ans + mod) % mod;
	cout << ans << endl;
}