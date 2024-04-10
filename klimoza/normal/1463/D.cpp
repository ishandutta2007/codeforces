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
const double eps = 1e-5;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
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
		vector<int> b(n);
		set<int> kek;
		set<pair<int, int>> mem;
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			kek.insert(b[i]);
			mem.insert(mp(b[i], i));
		}
		int m = 2 * n;
		vector<int> a;
		for (int i = 1; i <= 2 * n; i++) {
			if (kek.find(i) != kek.end()) continue;
			a.push_back(i);
		}
		vector<int> l(n), r(n);
		int ans1 = n + 1;
		for (int i = 0; i < n; i++) {
			auto it = mem.upper_bound(mp(a[i], 0));
			if (it == mem.end()) continue;
			int x = (*it).second;
			ans1 = min(ans1, x + n - i - 1);
		}
		mem.clear();
		for (int i = 0; i < n; i++)
			mem.insert(mp(-b[i], i));
		int ans2 = n + 1;
		for (int i = 0; i < n; i++) {
			auto it = mem.upper_bound(mp(-a[i], 0));
			if (it == mem.end()) continue;
			int x = (*it).second;
			ans2 = min(ans2, n - x + i - 1);
		}
		int ans = 0;
		for (int x = 0; x <= n; x++) {
			if (x <= ans1 && (n - x) <= ans2)
				ans++;
		}
		cout << ans << endl;
	}
	return;
}