/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
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

mt19937 mrand(239);

const double PI = acos((double)-1);
const double eps = 1e-5;
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
		int n, m; cin >> n >> m;
		vector<pair<ll, ll>>  a(m);
		for (auto& u : a)
			cin >> u.first >> u.second;
		vector<bool> used(m);
		int cnt = 0;
		vector<pair<ll, ll >> b(m);
		for (int i = 0; i < m; i++) {
			b[i] = { a[i].first, i };
		}
		vector<pair<ll, ll>> c(m);
		for (int i = 0; i < m; i++) {
			c[i] = { a[i].second, i };
		}
		sort(rall(c));
		sort(rall(b));
		ll tot = 0;
		ll ans = 0;
		for (int i = 0; i < m; i++) {
			while (cnt < n && cnt < m && b[cnt].first >= c[i].first) {
				used[b[cnt].second] = true;
				tot += b[cnt].first;
				cnt++;
			}
			if (cnt == n) ans = max(ans, tot);
			else if (cnt == n - 1) {
				if (used[c[i].second]) ans = max(ans, tot + c[i].first);
				else ans = max(ans, tot + a[c[i].second].first);
			}
			else {
				ll ed = n - cnt;
				ll cur = tot;
				//cout << ed << " " << cur << endl;
				if (!used[c[i].second]) {
					cur += a[c[i].second].first;
					ed--;
				}
				cur += ed * c[i].first;
				ans = max(ans, cur);
			}
			//cout << ans << " " << i << " " << c[i].first << " " << c[i].second << " " << cnt << "  " << tot << endl;
		}
		cout << ans << endl;
	}
	return;
}