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
	for (int i = n - 1; i >= 0; i--) {
		if (st[i] == '0') {
			ans[i] = 0;
			continue;
		}
		pair<int, int> v1 = { 0, 1 };
		pair<int, int> v2 = { 1, 0 };
		bool fl = true;
		for (int j = i + 1; j < n; j++) {
			if (st[j] == '0') {
				v1.first++;
			}
			else {
				v1.second = max(v1.first, v1.second) + 1;
			}
			if (ans[j] == 0) {
				v2.first++;
			}
			else {
				v2.second = max(v2.first, v2.second) + 1;
			}
			if (max(v1.first, v1.second) != max(v2.first, v2.second)) {
				fl = false;
				break;
			}
		}
		if (fl) ans[i] = 0;
		else ans[i] = 1;
	}
	for (int i : ans) cout << i;
}