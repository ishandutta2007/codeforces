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

#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

void solve();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

void solve() {
	string st;
	cin >> st;
	int n = st.size();
	vector<int> ans(n);
	int zero = 0;
	int one = 0;
	int nzero = 0;
	bool fl = true;
	pair<int, int> v1 = { 0, 0 };
	pair<int, int> v2 = { 0, 0 };
	for (int i = n - 1; i >= 0; i--) {
		if (st[i] == '0') {
			ans[i] = 0;
			v1.first++;
			v2.first++;
			continue;
		}
		v1.second++;
		if (max(v1.first, v1.second) != max(v2.first + 1, v2.second)) {
			ans[i] = 1;
			v2.second++;
		}
		else {
			ans[i] = 0;
			v2.first++;
		}
	}
	for (int i : ans) cout << i;
}