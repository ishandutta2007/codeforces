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
#include <queue>
#include <complex>

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll s; cin >> s;
		vector<pair<ll, ll>> h(n);
		for (int i = 0; i < n; i++) cin >> h[i].first >> h[i].second;
		sort(all(h));
		ll x = 0;
		for (int i = 0; i < n; i++) {
			x += h[i].first;
		}
		ll l = h[n / 2].first, r = s + 1;
		while (r - l > 1) {
			ll mid = l + r >> 1;
			vector<pair<ll, ll>> check;
			for (int i = 0; i < n; i++) {
				if (h[i].second >= mid) check.push_back(h[i]);
			}
			sort(all(check));
			bool fl = true;
			if (check.size() <= n / 2) fl = false;
			else {
				ll cur = x;
				for (int i = (int)check.size() - 1; i >= (int)check.size() - 1 - (n / 2); i--) {
					if (check[i].first < mid) {
						cur -= check[i].first;
						cur += mid;
					}
				}
			//	cout << cur << endl;
				if (cur <= s) fl = true;
				else fl = false;
			}
			//cout << mid << " " << check.size() << " " << fl << endl;
			if (fl) l = mid;
			else r = mid;
		}
		cout << l << endl;
	}
}