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
const double eps = 1e-7;
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
	int n; cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	vector<vector<int>> ans(n + 1, vector<int>(n, 0));
	sort(all(a));
	for (auto u : a) {
		int tp = -1;
		for (int j = 1; j <= n; j++) {
			if (ans[j] == ans[j - 1]) {
				ans[j][u.second] = 1;
				tp = j;
				break;
			}
		}
		int cnt = u.first - 1;
		if (tp == -1) cnt++;
		for (int j = 0; j <= n; j++) {
			if ((j == tp - 1) || j == tp) continue;
			if (!cnt) break;
			ans[j][u.second] = 1;
			cnt--;
		}
		if(tp != -1)
		for (int k = tp; k <= n; k++) {
			if (ans[k] == ans[tp - 1]) {
				for (int j = tp; j < k; j++) {
					swap(ans[j], ans[j - 1]);
				}
				break;
			}
		}
	}
	set<vector<int>> kek;
	for (auto u : ans){
		bool bl = false;
		for (int j : u)
			if (j)
				bl = true;
		if(bl)
		kek.insert(u);
	}
	cout << kek.size() << endl;
	for (auto u : kek) {
		for (int j : u)
			cout << j;
		cout << endl;
	}
	return;
}