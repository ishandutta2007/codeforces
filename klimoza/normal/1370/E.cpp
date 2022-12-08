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
	int n; cin >> n;
	string s, t;
	cin >> s >> t;
	string kek = "";
	int a[2], b[2];
	fill(a, a + 2, 0);
	fill(b, b + 2, 0);
	for (int i = 0; i < n; i++) {
		a[s[i] - '0']++;
		b[t[i] - '0']++;
	}
	if (a[0] != b[0] || a[1] != b[1]) {
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '0' && t[i] == '1')
			kek += "0";
		else if (s[i] == '1' && t[i] == '0')
			kek += "1";
	}
	if (kek.empty()) {
		cout << 0 << endl;
		return;
	}
	int bal = 0;
	for (int i = 0; i < kek.size(); i++) {
		if (kek[i] == '0') {
			kek = kek.substr(i + 1, kek.size() - i - 1) + kek.substr(0, i + 1);
			break;
		}
	}
	int ans = 0;
	for (int i = kek.size() - 1; i >= 0; i--) {
		if (kek[i] == '0') {
			bal = max(0, bal - 1);
		}
		else {
			bal++;
			ans = max(ans, bal);
		}
	}
	for (int i = 0; i < kek.size(); i++) {
		if (kek[i] == '1') {
			kek = kek.substr(i + 1, kek.size() - i - 1) + kek.substr(0, i + 1);
			break;
		}
	}
	bal = 0;
	for (int i = kek.size() - 1; i >= 0; i--) {
		if (kek[i] == '1') {
			bal = max(0, bal - 1);
		}
		else {
			bal++;
			ans = max(ans, bal);
		}
	}
	cout << ans << endl;
	return;
}