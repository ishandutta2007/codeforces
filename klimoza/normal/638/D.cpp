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

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

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

const int N = 105;

bool f[N][N][N];

bool check(int x, int y, int z) {
	if (!f[x][y][z]) return false;
	if (f[x - 1][y][z] && f[x + 1][y][z]) return true;
	if (f[x][y - 1][z] && f[x][y + 1][z]) return true;
	if (f[x][y][z - 1] && f[x][y][z + 1]) return true;
	if (f[x - 1][y][z] && f[x][y + 1][z] && !f[x - 1][y + 1][z]) return true;
	if (f[x - 1][y][z] && f[x][y][z + 1] && !f[x - 1][y][z + 1]) return true;
	if (f[x][y - 1][z] && f[x + 1][y][z] && !f[x + 1][y - 1][z]) return true;
	if (f[x][y - 1][z] && f[x][y][z + 1] && !f[x][y - 1][z + 1]) return true;
	if (f[x][y][z - 1] && f[x + 1][y][z] && !f[x + 1][y][z - 1]) return true;
	if (f[x][y][z - 1] && f[x][y + 1][z] && !f[x][y + 1][z - 1]) return true;
	return false;
}

void solve() {
	int n, m, t; cin >> n >> m >> t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				f[i][j][k] = false;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			string s; cin >> s;
			for (int k = 1; k <= t; k++) {
				f[i][j][k] = (bool)(int)(s[k - 1] - '0');
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= t; k++) {
				if (!f[i][j][k]) continue;
				ans += check(i, j, k);
			}
		}
	}
	cout << ans << endl;
}