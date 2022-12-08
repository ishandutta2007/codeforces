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
		ll W; cin >> W;
		ll x = (W + 1) / 2;
		vector<pair<ll, int>> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(all(a));
		while (!a.empty() && a.back().first > W)
			a.pop_back();
		ll s = 0;
		for (auto u : a)
			s += u.first;
		if (s < x) cout << -1 << endl;
		else {
			vector<int> ans;
			s = 0;
			reverse(all(a));
			for (auto u : a) {
				s += u.first;
				ans.push_back(u.second);
				if (s >= x) break;
			}
			cout << ans.size() << endl;
			for (int i : ans)
				cout << i + 1 << " ";
			cout << endl;
		}
	}
	return;
}