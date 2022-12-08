//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
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
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
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
		int n, m; cin >> n >> m;
		string s; cin >> s;
		int x = 0;
		vector<pair<int, int>> pref(n + 1);
		vector<int> xx(n);
		pref[0] = mp(0, 0);
		for (int i = 1; i <= n; i++) {
			if (s[i - 1] == '+')
				x++;
			else
				x--;
			xx[i - 1] = x;
			pref[i].first = max(pref[i - 1].first, x);
			pref[i].second = min(pref[i - 1].second, x);
		}
		vector<pair<int, int>> suff(n + 1, mp(xx[n - 1], xx[n - 1]));
		for (int i = n - 1; i >= 0; i--) {
			suff[i].first = max(suff[i + 1].first, xx[i]);
			suff[i].second = min(suff[i + 1].second, xx[i]);
		}
		for (int i = 0; i < m; i++) {
			int l, r; cin >> l >> r; l--; r--;
			pair<int, int> c = pref[l];
			pair<int, int> x = mp(suff[r + 1].first, suff[r + 1].second);
			//cout << c.first << " " << c.second << " " << x.first << " " << x.second  << " " << xx[r + 1 ] << endl;
			if (l) {
				x.first += xx[l - 1];
				x.second += xx[l - 1];
			}
			x.first -= xx[r];
			x.second -= xx[r];
			c.second = min(c.second, 0);
			c.first = max(c.first, 0);
			x.second = min(x.second, 0);
			x.first = max(x.first, 0);
			if (r == n - 1)
				cout << c.first - c.second + 1 << endl;
			else if (l == 0)
				cout << x.first - x.second + 1 << endl;
			else
				cout << max(x.first, c.first) - min(x.second, c.second) + 1 << endl;
		}
	}
	return;
}