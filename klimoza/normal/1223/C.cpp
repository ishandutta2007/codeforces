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

ll gcd(ll a, ll b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

void solve() {
	int q;
	cin >> q;
	while (q--) {
		int n; cin >> n;
		vector<ll> p(n);
		for (int i = 0; i < n; i++) cin >> p[i];
		sort(all(p), [](ll x, ll y) {return x > y; });
		ll x, a; cin >> x >> a;
		ll y, b; cin >> y >> b;
		ll k; cin >> k;
		int l = 0, r = n;
		ll cntxy, cntx, cnty;
		ll lc = lcm(a, b);
		//cout << lc << endl;
		cntxy = n / lc;
		cntx = n / a - cntxy;
		cnty = n / b - cntxy;
		int id = 0;
		ll ans = 0;
		//cout << cntxy << " " << cntx << " " << cnty << endl;
		for (; id < cntxy; id++) {
			ans += p[id] / 100 * (x + y);
		}
		if (x > y) {
			for (; id < cntxy + cntx; id++) {
				ans += p[id] / 100 * x;
			}
			for (; id < cntxy + cntx + cnty; id++) {
				ans += p[id] / 100 * y;
			}
		}
		else {
			for (; id < cntxy + cnty; id++) {
				ans += p[id] / 100 * y;
			}
			for (; id < cntxy + cntx + cnty; id++) {
				ans += p[id] / 100 * x;
			}
		}
		if (ans < k) {
			cout << -1 << endl;
			continue;
		}
		while (r - l > 1) {
			int mid = (l + r) / 2;
			cntxy = mid / lc;
			cntx = mid / a - cntxy;
			cnty = mid / b - cntxy;
			//cout << mid << " " << cntxy << " " << cntx << " " << cnty << endl;
			id = 0;
			ans = 0;
			for (; id < cntxy; id++) {
				ans += p[id] / 100 * (x + y);
			}
			if (x > y) {
				for (; id < cntxy + cntx; id++) {
					ans += p[id] / 100 * x;
				}
				for (; id < cntxy + cntx + cnty; id++) {
					ans += p[id] / 100 * y;
				}
			}
			else {
				for (; id < cntxy + cnty; id++) {
					ans += p[id] / 100 * y;
				}
				for (; id < cntxy + cntx + cnty; id++) {
					ans += p[id] / 100 * x;
				}
			}
			if (ans >= k) r = mid;
			else l = mid;
		}
		cout << r << endl;
	}
}