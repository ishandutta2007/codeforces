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

const int tp = 1e4;
const int N = 10;

int f[N][N];
double ans[N][N][tp];
double dp[N][N];

pair<int, int> nxt(int x, int y, int d) {
	while (d--) {
		if (x % 2 == 1) y--;
		else y++;
		if (y < 0) {
			x++;
			y = 0;
		}
		if (y == N) {
			y = N - 1;
			x++;
		}
	}
	return { x, y };
}

pair<int, int> go(int x, int y, int d) {
	while (d--) {
		if (x % 2 == 1) y++;
		else y--;
		if (y < 0) {
			x--;
			y = 0;
		}
		if (y == N) {
			y = N - 1;
			x--;
		}
	}
	return { x, y };
}

bool isOn(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < N);
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> f[i][j];
		}
	}
	int x = 0;
	int y = 1;
	ans[0][0][0] = 1;
	pair<int, int> h[7];
	dp[0][0] = 1;
	pair<int, int> t;
	while (true) {
		if (!isOn(x, y)) break;
		for (int r = 1; r <= 6; r++) {
			t = go(x, y, r);
			if (isOn(t.first, t.second) && f[t.first][t.second]) {
				double an1 = dp[t.first][t.second], an2 = dp[t.first - f[t.first][t.second]][t.second];
				if (an2 && an2 < an1) t = { t.first - f[t.first][t.second], t.second };
			}
			h[r] = t;
		}
		for (int cnt = 1; cnt < tp; cnt++) {
			for (int r = 1; r <= 6; r++) {
				t = h[r];
				if (!isOn(t.first, t.second)) ans[x][y][cnt] += ans[x][y][cnt - 1] / 6;
				else ans[x][y][cnt] += ans[t.first][t.second][cnt - 1] / 6;
			}
		}
		dp[x][y] = 0;
		for (int cnt = 1; cnt < tp; cnt++)
			dp[x][y] += cnt * ans[x][y][cnt];
		auto t = nxt(x, y, 1);
		x = t.first; y = t.second;
	}
	double an = 0;
	for (int cnt = 0; cnt < tp; cnt++) {
		an += (double)cnt * ans[N - 1][0][cnt];
	}
	cout << an << endl;
}