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

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 998244353;
void solve();

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
	for (int i = 0; i < n; i++) { cin >> a[i].first >> a[i].second;}
	int m; cin >> m;
	vector<pair<int, int>> b1(m);
	vector<pair<int, int>> b2(m);
	for (int i = 0; i < m; i++) { cin >> b1[i].first >> b1[i].second; }
	b2 = b1;
	sort(all(b1));
	sort(all(b2), [](pair<int, int> x, pair<int, int> y) {return x.second < y.second; });
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(a[i].first - b2[0].second, max(ans, b1.back().first - a[i].second));
	}
	cout << ans << endl;
}