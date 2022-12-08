#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
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

mt19937 mrand(43);

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

const int N = 2e3 + 2;

int p[N][N];

int intersect(pair<int, int> x, pair<int, int> y) {
	return max(0, min(x.second, y.second) - max(x.first, y.first) + 1);
}

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<pair<int, int>> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i].first >> a[i].second;
		a[i].first--; a[i].second--;
	}
	int ans = 0;
	for (int i = 0; i <= (n - k); i++) {
		for (int j = i; j <= (n - k); j++) {
			int l1 = i, r1 = i + k - 1;
			int l2 = j, r2 = j + k - 1;
			int c = 0;
			for (int t = 0; t < m; t++)
				c += max(intersect(mp(l1, r1), a[t]), intersect(mp(l2, r2), a[t]));
			ans = max(ans, c);
		}
	}
	cout << ans << endl;
	return;
}