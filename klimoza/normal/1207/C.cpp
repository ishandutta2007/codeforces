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
		ll n, a, b;
		cin >> n >> a >> b;
		string st;
		cin >> st;
		vector<pair<ll, ll>> ed;
		ed.push_back({ 0, 1 });
		for (int i = 1; i < n; i++) {
			if (st[i] == st[i - 1]) {
				ed[ed.size() - 1].second++;
			}
			else {
				ed.push_back({ st[i] - '0', 1 });
			}
		}
		if (ed.size() == 1) {
			cout << n * a + (n + 1) * b << endl;
		}
		else {
			ll cnt = ed[0].second + ed.back().second;
			ll ans = (cnt + 2) * a + (cnt + 2) * b;
			for (int i = 1; i < ed.size() - 1; i++) {
				if (ed[i].first == 1) ans += ed[i].second * (a + 2 * b);
				else {
					ans += 2 * b;
					ans += min((ed[i].second - 1) * b + (ed[i].second * a) + 2 * a, (ed[i].second - 1) * 2 * b + ed[i].second * a);
				}
			}
			cout << ans << endl;
		}
	}
}