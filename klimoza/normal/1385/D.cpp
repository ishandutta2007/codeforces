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

mt19937 mrand(239);

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

const int N = 131072;
const int A = 26;

int pref[N][A];

int get(int l, int r, int c = 0) {
	int len = r - l;
	int x = 0;
	if (l) x = pref[l - 1][c];
	int y = pref[r - 1][c];
	int m = l + r >> 1;
	if (len == 1) {
		return len - (y - x);
	}
	else {
		return min(len / 2 - (pref[m - 1][c] - x) + get(m, r, c + 1), len / 2 - (y - pref[m - 1][c]) + get(l, m, c + 1));
	}
}

void solve(){
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			for (int c = 0; c < A; c++) {
				pref[i][c] = 0;
			}
		}
		string s; cin >> s;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < A; j++) {
				if (i) pref[i][j] = pref[i - 1][j];
				if (s[i] == (j + 'a')) pref[i][j]++;
			}
		}
		cout << get(0, n) << endl;
	}
	return;
}