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
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int tmp = k;
		k = k * 2 + 10;
		vector<int>a(n);
		for (int& i : a) cin >> i;
		vector<int> p(k + 1);
		vector<int> s(k + 1);
		vector<int> ans(k + 1);
		for (int i = 0; i < n / 2; i++) {
			int x = a[i];
			int y = a[n - i - 1];
			p[min(x, y)] += 2;
			s[min(x, y) + 1] += 1;
			ans[x + y] -= 1;
			s[max(x, y) + tmp + 1] += 1;
		}
		int cur = 0;
		for (int i = 0; i < k; i++) {
			cur += s[i];
			//cout << i << " " << cur << endl;
			ans[i] += cur;
		}
		cur = 0;
		int kek = 2e9;
		for (int i = k - 1; i > 0; i--) {
			cur += p[i];
			ans[i] += cur;
			//cout << i << " " << ans[i] << endl;
			kek = min(kek, ans[i]);
		}
		cout << kek << endl;
	}
	return;
}