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
		int x, y;
		cin >> x >> y;
		int a = x, b = y;
		if (a > b) swap(a, b);
		if (3 * a + 1 < b) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		if (x >= y) {
			for (int i = 0; i < y; i++) {
				cout << 2 << " " << (i + 1) * 2 << "\n";
				if (i != y - 1) cout << 2 << " " << 2 * (i + 1) + 1 << "\n";
			}
			x -= (y - 1);
			if (x) {
				cout << 2 << " " << 2 * y + 1 << "\n";
				x--;
			}
			if (x) {
				cout << 2 << " " << 1 << "\n";
				x--;
			}
			if (!x) continue;
			for (int i = 0; i < y; i++) {
				if (!x) break;
				if (x == 1) {
					cout << 1 << " " << 2 * (i + 1) << "\n";
					x--;
				}
				else {
					cout << 1 << " " << 2 * (i + 1) << "\n" << 3 << " " << 2 * (i + 1) << "\n";
					x -= 2;
				}
			}
		}
		else {
			swap(x, y);
			for (int i = 0; i < y; i++) {
				cout << 3 << " " << (i + 1) * 2 << "\n";
				if (i != y - 1) cout << 3 << " " << 2 * (i + 1) + 1 << "\n";
			}
			x -= (y - 1);
			if (x) {
				cout << 3 << " " << 2 * y + 1 << "\n";
				x--;
			}
			if (x) {
				cout << 3 << " " << 1 << "\n";
				x--;
			}
			if (!x) continue;
			for (int i = 0; i < y; i++) {
				if (!x) break;
				if (x == 1) {
					cout << 2 << " " << 2 * (i + 1) << "\n";
					x--;
				}
				else {
					cout << 2 << " " << 2 * (i + 1) << "\n" << 4 << " " << 2 * (i + 1) << "\n";
					x -= 2;
				}
			}
		}
	}
}