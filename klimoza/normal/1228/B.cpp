#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <complex>

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
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
	int h, w;
	cin >> h >> w;
	vector<int> r(h);
	vector<int> c(w);
	for (int i = 0; i < h; i++) cin >> r[i];
	for (int i = 0; i < w; i++) cin >> c[i];
	vector<vector<pair<int, int>>> a(h, vector<pair<int, int>>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < r[i]; j++) {
			a[i][j].first = 1;
		}
		if (r[i] != w) a[i][r[i]].first = -1;
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < c[i]; j++) {
			if (a[j][i].first == -1) {
				cout << 0 << endl;
				return;
			}
			a[j][i].second = 1;
		}
		if (c[i] != h) {
			if (a[c[i]][i].first == 1) {
				cout << 0 << endl;
				return;
			}
			a[c[i]][i].second = -1;
		}
	}
	ll modd = 1e9 + 7;
	ll cur = 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!a[i][j].first && !a[i][j].second) {
				cur *= 2;
				cur %= modd;
			}
		}
	}
	cout << cur << endl;
}