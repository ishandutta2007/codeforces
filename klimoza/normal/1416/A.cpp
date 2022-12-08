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

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		vector<int> kek(n, n + 1);
		vector<int> nxt(n, n);
		vector<int> prv(n, -1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
			kek[a[i]] = 0;
		}
		vector<int> lol(n, n);
		for (int i = n - 1; i >= 0; i--) {
			nxt[i] = lol[a[i]];
			lol[a[i]] = i;
		}
		for (int i = 0; i < n; i++)
			lol[i] = -1;
		for (int i = 0; i < n; i++) {
			prv[i] = lol[a[i]];
			lol[a[i]] = i;
		}
		for (int i = n - 1; i >= 0; i--) {
			kek[a[i]] = max(kek[a[i]], max(nxt[i] - i, i - prv[i]));
		}
		vector<pair<int, int>> b(n);
		for (int i = 0; i < n; i++)
			b[i] = { kek[i], i };
		//for (auto u : b)cout << u.first << " " << u.second << endl;
		sort(all(b));
		int l = 1;
		vector<int> ans(n + 1);
		int cur = n;
		vector<int> upd(n + 1, n);
		for (auto u : b) {
			if (u.first == n + 1) break;
			upd[u.first] = min(upd[u.first], u.second);
		}
		for (int i = 1; i <= n; i++) {
			upd[i] = min(upd[i], upd[i - 1]);
			ans[i] = upd[i];
		}
		for (int i = 1; i <= n; i++) {
			if (ans[i] == n) cout << -1 << " ";
			else cout << ans[i] + 1 << " ";
		}
		cout << endl;
	}
	return;
}