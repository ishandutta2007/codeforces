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
#include <queue>
#include <complex>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

//#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;
const ll mod2 = mod * mod;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

void solve() {
	int n, k; cin >> n >> k;
	vector<int> c(k);
	for (int i = 0; i < k; i++) {
		c[i] = i + 1;
	}
	int f = 0;
	pair<int, int> t1, t2;
	cout << "? ";
	for (int i : c) cout << i << " ";
	cout << endl;
	cin >> t1.first >> t1.second;
	cout << "? ";
	for (int i : c) {
		if (i == t1.first) continue;
		cout << i << " ";
	}
	cout << k + 1 << endl;
	cin >> t2.first >> t2.second;
	c.push_back(k + 1);
	int cnt = 1;
	pair<int, int> x;
	f = 2;
	assert(f <= n);
	for (int i = 1; i <= k + 1; i++) {
		if (i == t1.first || i == t2.first) continue;
		cout << "? ";
		for (int j : c) {
			if (j == i) continue;
			cout << j << " ";
		}
		cout << endl;
		f++;
		assert(f <= n);
		cin >> x.first >> x.second;
		if (x.second == max(t1.second, t2.second))
			cnt++;
	}
	cout << "! " << cnt << endl;
	return;
}