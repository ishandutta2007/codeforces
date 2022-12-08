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
		vector<pair<int, int>> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] >= 0) b[i] = { a[i], 1 };
			else b[i] = { -a[i], 0 };
		}
		vector<pair<int, int>> f1, f2;
		vector<pair<int, int>> t1, t2;
		for (auto u : b) {
			if (u.second == 1) f1.push_back(u);
			else f2.push_back(u);
		}
		sort(rall(f1));
		sort(rall(f2));
		t1 = f1; t2 = f2;
		reverse(all(t1));
		reverse(all(t2));
		ll ans = -inf;
		for (int i = 0; i <= 5; i++) {
			if (f1.size() < i) break;
			int j = 5 - i;
			if (f2.size() < j) continue;
			ll s = 1;
			if (j & 1) {
				for (int k = 0; k < i; k++) {
					s *= t1[k].first;
				}
				for (int k = 0; k < j; k++)
					s *= (-t2[k].first);
			}
			else {
				for (int k = 0; k < i; k++) {
					s *= f1[k].first;
				}
				for (int k = 0; k < j; k++)
					s *= (-f2[k].first);
			}
			ans = max(ans, s);
		}
		cout << ans << endl;
	}
	return;
}