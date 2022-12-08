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

bool check(int n, int i, int b) {
	if (n % 2 == 0) {
		if (i + 1 == n / 2)
			return true;
		return false;
	}
	else {
		if (b == 0 && 2 * (i + 1) == n + 1)
			return true;
		else if (b == 1 && 2 * (i + 1) == n - 1)
			return true;
		return false;
	}
}

void solve() {
	int n; cin >> n;
	vector<pair<ll, int>> a(n);
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
		cur += a[i].first;
	}
	if (n == 2) {
		cout << -a[0].first - a[1].first << endl;
		return;
	}
	ll ans = -inf;
	if (n % 3 == 1) ans = max(ans, cur);
	bool fl = false;
	sort(all(a));
	for (int i = 0; i < n; i++) {
		if (i && ((a[i].second & 1) != (a[i - 1].second & 1))) fl = true;
		cur -= 2 * a[i].first;
		//cout << fl << " " << (i + 1) << " " << cur << endl;
		if (!fl && check(n, i, a[i].second & 1)) {
			if(i < (n - 1) && (n + (i + 1)) % 3 == 1)
				ans = max(ans, cur + 2 * a[i].first - 2 * a[i + 1].first);
			continue;
		}
		if ((n + (i + 1)) % 3 == 1)
			ans = max(ans, cur);
	}
	cout << ans << endl;
	return;
}