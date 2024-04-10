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

const int N = 2e5 + 7;

vector<vector<vector<int>>> pref(N, vector<vector<int>>(3, vector<int>(3, 0)));

void solve() {
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		string st;
		cin >> st;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < n; k++) {
					pref[k][i][j] = 0;
				}
			}
		}
		while (size(st) < 3) st = st + "0";
		if (st[0] == 'R') {
			pref[0][0][1] = 1;
			pref[0][0][2] = 1;
		}
		else if (st[0] == 'G') {
			pref[0][0][0] = 1;
			pref[0][0][2] = 1;
		}
		else {
			//cout << "suka\n";
			pref[0][0][1] = 1;
			pref[0][0][0] = 1;
		}
		pref[1][0] = pref[0][0];
		if (st[1] == 'R') {
			pref[1][1][1] = 1;
			pref[1][1][2] = 1;
		}
		else if (st[1] == 'G') {
			pref[1][1][0] = 1;
			pref[1][1][2] = 1;
		}
		else {
			pref[1][1][1] = 1;
			pref[1][1][0] = 1;
		}
		pref[2][0] = pref[1][0];
		pref[2][1] = pref[1][1];
		if (st[2] == 'R') {
			pref[2][2][1] = 1;
			pref[2][2][2] = 1;
		}
		else if (st[2] == 'G') {
			pref[2][2][0] = 1;
			pref[2][2][2] = 1;
		}
		else {
			pref[2][2][1] = 1;
			pref[2][2][0] = 1;
		}
		for (int i = 3; i < n; i++) {
			pref[i] = pref[i - 1];
			pref[i] = pref[i - 1];
			pref[i] = pref[i - 1];
			if (st[i] == 'R') {
				pref[i][i % 3][1]++;
				pref[i][i % 3][2]++;
			}
			else if (st[i] == 'G') {
				pref[i][i % 3][0]++;
				pref[i][i % 3][2]++;
			}
			else {
				pref[i][i % 3][1]++;
				pref[i][i % 3][0]++;
			}
		}
		/*cout << pref[0][0][1] << endl;
		for (int i = 0; i < n; i++) {
			cout << i << ":\n";
			for (int j = 0; j < 3; j++) {
				if (j == 0) cout << "   R:\n";
				else if (j == 1) cout << "   G:\n";
				else cout << "   B:\n";
				for (int k = 0; k < 3; k++) {
					cout << "      " << k << ": " << pref[i][k][j] << "\n";
				}
			}
		}*/
		int ans = inf0;
		for (int i = 0; i <= n - k; i++) {
			int cur1 = pref[i + k - 1][i % 3][0] + pref[i + k - 1][(i % 3 + 1) % 3][1] + pref[i + k - 1][(i % 3 + 2) % 3][2];
			if (i > 0) cur1 -= pref[i - 1][i % 3][0] + pref[i - 1][(i % 3 + 1) % 3][1] + pref[i - 1][(i % 3 + 2) % 3][2];
			int cur2 = pref[i + k - 1][(i % 3 + 1) % 3][0] + pref[i + k - 1][(i % 3 + 2) % 3][1] + pref[i + k - 1][(i % 3 + 0) % 3][2];
			if (i > 0) cur2 -= pref[i - 1][(i % 3 + 1) % 3][0] + pref[i - 1][(i % 3 + 2) % 3][1] + pref[i - 1][(i % 3 + 0) % 3][2];
			int cur3 = pref[i + k - 1][(i % 3 + 2) % 3][0] + pref[i + k - 1][(i % 3 + 0) % 3][1] + pref[i + k - 1][(i % 3 + 1) % 3][2];
			if (i > 0) cur3 -= pref[i - 1][(i % 3 + 2) % 3][0] + pref[i - 1][(i % 3 + 0) % 3][1] + pref[i - 1][(i % 3 + 1) % 3][2];
			ans = min(min(ans, cur1), min(cur3, cur2));
		}
		cout << ans << endl;
	}
}