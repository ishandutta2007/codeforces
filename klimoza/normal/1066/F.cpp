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

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

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

const int N = 2e5 + 7;

ll dp[N][2];

ll dist(pair<int, int> x, pair<int, int> y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(all(a), [](pair<int, int> x, pair<int, int> y) {
		if (max(x.first, x.second) == max(y.first, y.second)) {
			if (x.first == y.first) return x.second > y.second;
			return x.first < y.first;
		}
		return max(x.first, x.second) < max(y.first, y.second);
	});
	//for (auto u : a) cout << u.first << " " << u.second << endl; cout << " WHA AA A A\n";
	vector<pair<pair<int, int>, pair<int, int>>> ed;
	ed.push_back({ a[0], a[0]});
	for (int i = 1; i < n; i++) {
		if (max(ed.back().first.first, ed.back().first.second) == max(a[i].first, a[i].second)) {
			ed.back().second = a[i];
		}
		else {
			ed.push_back({ a[i], a[i] });
		}
	}
	//for (auto u : ed) cout << u.first.first << " " << u.first.second << endl; 	cout << " ------ \n";
	dp[0][0] = dist({ 0, 0 }, ed[0].second) + dist(ed[0].second, ed[0].first);
	dp[0][1] = dist({ 0, 0 }, ed[0].first) + dist(ed[0].first, ed[0].second);
	for (int i = 1; i < ed.size(); i++) {
		dp[i][0] = min(dp[i - 1][0] + dist(ed[i - 1].first, ed[i].second), dp[i - 1][1] + dist(ed[i - 1].second, ed[i].second)) + dist(ed[i].first, ed[i].second);
		dp[i][1] = min(dp[i - 1][0] + dist(ed[i - 1].first, ed[i].first), dp[i - 1][1] + dist(ed[i - 1].second, ed[i].first)) + dist(ed[i].first, ed[i].second);
		//cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
	}
	cout << min(dp[ed.size() - 1][0], dp[ed.size() - 1][1]) << endl;
}