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
const ll mod = 1e9 + 7;
//const ll mod2 = 998244353;

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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	if (n == 1) {
		cout << 0 << endl;
		return;
	}
	pair<int, int> last = { -1, -1 };
	vector<int> a(n);
	vector<pair<int, int>> cool;
	set<int> od, od2;
	for (int i = 1; i <= n; i += 2)
		od.insert(i);
	for (int i = 2; i <= n; i += 2)
		od2.insert(i);
	int t1 = (n + 1) / 2, t2 = n / 2;
	int f = -1, t = -1;
	int cc = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i]) {
			if (a[i] & 1) t1--;
			else t2--;
			if (f == -1) f = i;
			t = i;
			if (last.first != -1 && last.first % 2 == a[i] % 2)
				cool.push_back({ last.second, i });
			else if (last.first != -1 && last.first % 2 != a[i] % 2) {
				cc++;
			}
			last = { a[i], i };
		}
	}
	sort(all(cool), [](pair<int, int> x, pair<int, int> y){
	    return x.second - x.first < y.second - y.first;
	});
	if (t1 + t2 == n) {
		cout << 1 << endl;
		return;
	}
	int ans = inf0;
	for (int m = 0; m < 4; m++) {
		int c1 = t1, c2 = t2;
		int cur = cc;
		if (m & 1) {
			if (a[f] & 1) c1 -= f;
			else c2 -= f;
		}
		else {
			cur++;
		}
		if (m & 2) {
			if (a[t] & 1) c1 -= (n - t - 1);
			else c2 -= (n - t - 1);
		}
		else {
			cur++;
		}
		if (c1 < 0 || c2 < 0) continue;
		for (auto u : cool) {
			if (a[u.first] & 1) {
				if (u.second - u.first - 1 <= c1) c1 -= (u.second - u.first - 1);
				else cur += 2;
			}
			else {
				if (u.second - u.first - 1 <= c2) c2 -= (u.second - u.first - 1);
				else cur += 2;
			}
		}
		ans = min(ans, cur);
	}
	cout << ans << endl;
	return;
}