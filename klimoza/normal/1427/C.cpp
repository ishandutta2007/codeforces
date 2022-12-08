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

struct item {
	int t, x, y;
	item() {}
	item(int t, int x, int y) : t(t), x(x), y(y) {}
};

int ds(item a, item b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve() {
	int r, n; cin >> r >> n;
	vector<item> a(n + 1);
	a[0] = item(0, 1, 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i + 1].t >> a[i + 1].x >> a[i + 1].y;
	}
	n++;
	vector<int> dp(n, 0);
	vector<int> maxi(n, 0);
	dp[0] = 1;
	maxi[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (a[i].t - a[j].t >= 1000) {
				dp[i] = max(dp[i], maxi[j] + 1);
				break;
			}
			else {
				if (a[j].t + ds(a[j], a[i]) <= a[i].t)
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] == 1)
			dp[i] = 0;
		maxi[i] = max(maxi[i - 1], dp[i]);
	}
	cout << maxi[n - 1] - 1 << endl;
	return;
}