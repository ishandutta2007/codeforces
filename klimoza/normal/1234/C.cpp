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
const ll mod = 1e9 + 7;

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
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int x = 0, y = 0;
		int type = 2;
		vector<vector<int>> ar(2, vector<int>(n));
		for (int i = 0; i < 2; i++) {
			string st;
			cin >> st;
			for (int j = 0; j < n; j++) {
				ar[i][j] = st[j] - '0';
			}
		}
		while (true) {
			if (y == n && x == 0) {
				cout << "NO\n";
				break;
			}
			if (y == n && x == 1) {
				cout << "YES\n";
				break;
			}
			if (ar[x][y] <= 2) {
				if (type == 2) {
					y++;
				}
				else {
					cout << "NO\n";
					break;
				}
			}
			else {
				if (type == 1) {
					type = 2;
					y++;
				}
				else if (type == 2) {
					if (x == 0) {
						type = 1;
						x++;
					}
					else {
						type = 3;
						x--;
					}
				}
				else {
					type = 2;
					y++;
				}
			}
		}
	}
}