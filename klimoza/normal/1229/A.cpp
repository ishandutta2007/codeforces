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

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

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
	int n; cin >> n;
	vector<ll> b(n);
	vector<pair<ll, ll>> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first;
	for (int i = 0; i < n; i++) a[i].second = i;
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(all(a));
	ll ans = 0;
	vector<bool> used(n);
	for (int i = 1; i < n; i++) {
		if (a[i].first == a[i - 1].first) {
			used[i] = true;
			used[i - 1] = true;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) continue;
		for (int j = 0; j < n; j++) {
			if (used[j]) continue;
			if ((a[i].first & a[j].first) == a[j].first) {
				used[j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (used[i]) {
			ans += b[a[i].second];
			cnt++;
		}
	}
	if (cnt >= 2)
		cout << ans << endl;
	else
		cout << 0 << endl;
}