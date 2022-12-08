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

#define all(v) (v).begin(), (v).end()
#define size(v) (v).size()

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
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int upper = 1e5;
		int lower = -1e5;
		int left = -1e5;
		int right = 1e5;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			int f1, f2, f3, f4;
			cin >> f1 >> f2 >> f3 >> f4;
			if (!f1) left = max(left, x);
			if (!f4) lower = max(lower, y);
			if (!f3) right = min(right, x);
			if (!f2) upper = min(upper, y);
		}
		if (upper < lower || right < left) cout << 0 << endl;
		else cout << 1 << " " << left << " " << lower << "\n";
	}
}