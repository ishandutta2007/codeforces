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

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	int cnt[65];
	fill(cnt, cnt + 65, 0);
	for (int i = 0; i < n; i++) {
		ll cur = a[i];
		ll t = 0;
		while (cur % 2 == 0) {
			cur >>= 1;
			t++;
		}
		cnt[t]++;
	}
	int maxi = 0;
	for (int i = 0; i < 65; i++) {
		if (cnt[maxi] < cnt[i]) maxi = i;
	}
	cout << n - cnt[maxi] << endl;
	for (int i = 0; i < n; i++) {
		ll cur = a[i];
		ll t = 0;
		while (cur % 2 == 0) {
			cur >>= 1;
			t++;
		}
		if (t != maxi) cout << a[i] << " ";
	}
}