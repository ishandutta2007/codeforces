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

#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

//#define endl '\n'


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
	int n, m; cin >> n >> m;
	int x = n / m;
	vector<int> c(m, 0);
	vector<vector<int>> p(m);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[a[i] % m]++;
		p[a[i] % m].push_back(i);
	}
	int r = 0;
	int ans = 0;
	bool fl = false;
	for (int i = 0; i < m; i++) {
		if (i == r)
			fl = false;
		if (c[i] <= x)
			continue;
		if (!fl)
			r = i;
		fl = true;
		while (c[i] > x) {
			while (c[r] >= x)
				r = (r + 1) % m;
			int t = p[i].back();
			a[t] += (r - i + m) % m;
			ans += (r - i + m) % m;
			p[i].pop_back();
			c[r]++;
			c[i]--;
		}
	}
	cout << ans << endl;
	for (int i : a)
		cout << i << " ";
	return;
}