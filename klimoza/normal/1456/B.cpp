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

//#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

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

const int L = 31;

int maxbit(int a) {
	for (int i = L - 1; i >= 0; i--) {
		if (a & (1 << i))
			return i;
	}
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 2; i < n; i++) {
		if (maxbit(a[i - 2]) == maxbit(a[i - 1]) && maxbit(a[i - 1]) == maxbit(a[i])) {
			cout << 1 << endl;
			return;
		}
	}
	vector<vector<pair<int, int>>> mem(n);
	int ans = inf0;
	for (int i = 0; i < n; i++) {
		int c = a[i];
		for (int j = i - 1; j >= 0; j--) {
			mem[i].push_back(mp(c, (i - j - 1)));
			for (auto v : mem[j]) {
				if (v.first > c)
					ans = min(ans, v.second + i - j - 1);
			}
			c ^= a[j];
		}
		mem[i].push_back(mp(c, i));
	}
	if (ans == inf0) cout << -1 << endl;
	else cout << ans << endl;
	return;
}