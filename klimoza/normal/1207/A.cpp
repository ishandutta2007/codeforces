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
	int t;
	cin >> t;
	while (t--) {
		ll b, p, f, h, c;
		cin >> b >> p >> f >> h >> c;
		ll ans = 0;
		if (h > c) {
			ll cnt = min(b / 2, p);
			ans += cnt * h;
			b -= 2 * cnt;
			p -= cnt;
		}
		else {
			ll cnt = min(b / 2, f);
			ans += cnt * c;
			b -= 2 * cnt;
			f -= cnt;
		}
		if (b < 2) cout << ans << endl;
		else {
			if (p > 0) {
				ll cnt = min(b / 2, p);
				ans += cnt * h;
				b -= 2 * cnt;
				p -= cnt;
			}
			else {
				ll cnt = min(b / 2, f);
				ans += cnt * c;
				b -= 2 * cnt;
				f -= cnt;
			}
			cout << ans << endl;
		}
	}
}