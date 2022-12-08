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

const double PI = acos((double)-1);
const double eps = 1e-7;
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

void solve() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = s.size();
		set<pair<pair<int, int>, pair<int, int>>> kek;
		int x = 0, y = 0;
		int ans = 0;
		for (char c : s) {
			int cx = x, cy = y;
			if (c == 'S') cx++;
			else if (c == 'N') cx--;
			else if (c == 'E') cy++;
			else if (c == 'W') cy--;
			if (kek.find({ {x, y}, {cx, cy} }) != kek.end()) ans++;
			else {
				ans += 5;
				kek.insert({ {x, y}, {cx, cy} });
				kek.insert({ {cx, cy}, {x, y} });
			}
			x = cx; y = cy;
		}
		cout << ans << endl;
	}
	return;
}