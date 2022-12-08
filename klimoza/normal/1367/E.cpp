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

int gcd(int a, int b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

int cnt[26];

void solve() {
	int t; cin >> t;
	while (t--) {
		fill(cnt, cnt + 26, 0);
		int n, k; cin >> n >> k;
		string s; cin >> s;
		for (char c : s) {
			cnt[c - 'a']++;
		}
		int ans = 0;
		for (int len = 1; len <= n; len++) {
			int g = gcd(len, k);
			int mem = g;
			for (int i = 0; i < 26; i++) {
				mem -= (cnt[i] / (len / g));
			}
			if (mem <= 0)
				ans = len;
		}
		cout << ans << endl;
	}
	return;

}