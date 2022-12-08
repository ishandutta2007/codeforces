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

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
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

const int N = 7e4 + 2;

bitset<N> tmp;
bitset<N> dp;

bool used[N];
int frst[N];

int find_first() {
	for (int i = 0; i < N; i++)
		if (tmp[i])
			return i;
	return -1;
}

void solve() {
	fill(frst, frst + N, -1);
	int n, s;
	cin >> n >> s;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	for (int i = 0; i <= n; i++) {
		dp[i] = 0;
		used[i] = false;
	}
	sort(all(a));
	if (a.back().first > s) {
		cout << -1 << endl;
		return;
	}
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int x = a[i - 1].first;
		tmp = dp;
		dp = dp | (dp << x);
		tmp = dp ^ tmp;
		while (tmp.count()) {
			int kek = tmp._Find_first();
			frst[kek] = i - 1;
			tmp[kek] = 0;
		}
	}
	if (!dp[s - a.back().first]) {
		cout << -1 << endl;
		return;
	}
	used[n - 1] = true;
	int x = s - a.back().first;
	while (x) {
		int i = frst[x];
		used[i] = true;
		x -= a[i].first;
	}
	vector<int> c(n);
	vector<vector<int>> ans(n);
	vector<pair<int, int>> kek;
	for (int i = 0; i < n - 1; i++) {
		if (used[i])
			c[a[i].second] = a[i].first;
		else
			kek.push_back(a[i]);
	}
	if (kek.empty())
		c[a.back().second] = a.back().first;
	else {
		c[kek[0].second] = kek[0].first;
		for (int i = 1; i < kek.size(); i++) {
			c[kek[i].second] = kek[i].first - kek[i - 1].first;
			ans[kek[i].second].push_back(kek[i - 1].second);
		}
		c[a.back().second] = a.back().first - kek.back().first;
		ans[a.back().second].push_back(kek.back().second);
	}
	for (int i = 0; i < n; i++) {
		cout << c[i] << " " << ans[i].size() << " ";
		for (int j : ans[i])
			cout << j + 1 << " ";
		cout << endl;
	}
	return;
}