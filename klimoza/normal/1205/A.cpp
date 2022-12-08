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
	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		vector<int> a(2 * n);
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				a[i] = 2 * i;
				a[i + n] = 2 * i + 1;
			}
			else {
				a[i] = 2 * i + 1;
				a[i + n] = 2 * i;
			}
		}
		for (int i : a) cout << i + 1 << " ";
		cout << endl;

	}
}