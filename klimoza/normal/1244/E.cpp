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

#define int long long

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
	int n; ll k; cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(all(a));
	int l = 0, r = n - 1;
	if (a[l] == a[r]) {
		cout << 0 << endl;
		return;
	}
	while ((l + 1) < n && a[l + 1] == a[l]) l++;
	while ((r - 1) >= 0 && a[r - 1] == a[r]) r--;
	ll curlef = a[l];
	ll currig = a[r];
	while (k > 0) {
		int cnt1 = l + 1;
		int cnt2 = n - r;
		if (curlef == currig) {
			break;
		}
		if (cnt1 < cnt2) {
			ll dd = a[l + 1] - curlef;
			if ((dd * cnt1) > k) {
				curlef += (k / cnt1);
				k = 0;
			}
			else {
				k -= dd * cnt1;
				curlef += dd;
				while ((l + 1) < n && a[l + 1] == curlef) l++;
			}
		}
		else {
			ll dd = currig - a[r - 1];
			if ((dd * cnt2) > k) {
				currig -= (k / cnt2);
				k = 0;
			}
			else {
				k -= dd * cnt2;
				currig -= dd;
				while ((r - 1) >= 0 && a[r - 1] == currig) r--;
			}
		}
	}
	cout << currig - curlef << endl;
}