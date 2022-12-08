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

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;
const ll mod2 = mod * mod;

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
	int m; cin >> m;
	while (m--) {
		int n; ll t, a, b; cin >> n >> t >> a >> b;
		ll c1 = 0, c2 = 0;
		vector<pair<ll, int>> q(n);
		ll t1 = 0, t2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> q[i].second;
			if (q[i].second) t2++;
			else t1++;
		}
		for (int i = 0; i < n;i++) {
			cin >> q[i].first;
		}
		q.push_back({ -1, -1 });
		sort(all(q));
		ll ans = 0;
		n++;
		for (int i = 0; i < n; i++) {
			if (q[i].second == 1) c2++;
			else if(q[i].second == 0) c1++;
			ll f = 0;
			if (i == n - 1) f = t;
			else f = q[i + 1].first - 1;
			if (c2 * b + c1 * a > f) continue;
			ll l = t1 - c1;
			f -= c2 * b + c1 * a;
			ll tmp = c1 + c2;
			l = min(f / a, l);
			f -= l * a;
			tmp += l;
			l = t2 - c2;
			l = min(f / b, l);
			tmp += l;
			ans = max(ans, tmp);
		}
		cout << ans << endl;
	}
	return;
}