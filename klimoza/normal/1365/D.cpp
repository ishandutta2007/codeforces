/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
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
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
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

const int N = 51;

char f[N][N];
bool used[N][N];

int n, m;

void dfs(int x, int y) {
	used[x][y] = true;
	if (x && f[x - 1][y] != '#' && !used[x - 1][y])
		dfs(x - 1, y);
	if (y && f[x][y - 1] != '#' && !used[x][y - 1])
		dfs(x, y - 1);
	if (x < (n - 1) && f[x + 1][y] != '#' && !used[x + 1][y])
		dfs(x + 1, y);
	if (y < (m - 1) && f[x][y + 1] != '#' && !used[x][y + 1])
		dfs(x, y + 1);
}

void solve() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> f[i][j];
				used[i][j] = false;
			}
		}
		bool fl = true;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(f[i][j] == 'G')
					cnt++;
				if (f[i][j] == 'B') {
					if (i) {
						if (f[i - 1][j] == 'G') fl = false;
						else if (f[i - 1][j] == '.') f[i - 1][j] = '#';
					}
					if (j) {
						if (f[i][j - 1] == 'G') fl = false;
						else if (f[i][j - 1] == '.') f[i][j - 1] = '#';
					}
					if (i < (n - 1)) {
						if (f[i + 1][j] == 'G') fl = false;
						else if (f[i + 1][j] == '.') f[i + 1][j] = '#';
					}
					if (j < (m - 1)) {
						if (f[i][j + 1] == 'G') fl = false;
						else if (f[i][j + 1] == '.') f[i][j + 1] = '#';
					}
				}
			}
		}
		if (!fl) cout << "No\n";
		else {
			if (!cnt) cout << "Yes\n";
			else {
				if (f[n - 1][m - 1] == '#')
					cout << "No\n";
				else {
					dfs(n - 1, m - 1);
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							if (f[i][j] == 'G' && !used[i][j])
								fl = false;
						}
					}
					if (fl) cout << "Yes\n";
					else cout << "No\n";
				}
			}
		}
	}
	return;
}