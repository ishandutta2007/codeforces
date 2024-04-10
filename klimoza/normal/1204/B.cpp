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
const ll mod = 1e9 + 7;

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

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	vector<ll> a(n);
	a[0] = 1;
	ll suma = 1;
	for (int i = 1; i < l; i++) {
		a[i] = a[i - 1] * 2;
		suma += a[i];
	}
	ll ans1 = suma + n - l;
	for (int i = l; i < min(n, r); i++) {
		a[i] = a[i - 1] * 2;
		suma += a[i];
	}
	for (int i = r; i < n; i++) {
		a[i] = a[i - 1];
		suma += a[i];
	}
	ll ans2 = suma;
	cout << ans1 << " " << ans2 << endl;
}