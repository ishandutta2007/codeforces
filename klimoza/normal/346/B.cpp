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
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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

const int N = 1e2 + 1;
const int A = 26;

int dp[N][N][N];
bool used[N][N][N];
int to[N][A];

struct Item {
	int a, b, c;
	Item() {}
	Item(int a, int b, int c) : a(a), b(b), c(c) {}
};

Item p[N][N][N];


void solve() {
	string a, b, s;
	cin >> a >> b >> s;
	int n = a.size(), m = b.size(), t = s.size();
	for (int i = 0; i < t; i++) {
		for (char c = 'A'; c <= 'Z'; c++) {
			string x = s.substr(0, i) + c;
			to[i][c - 'A'] = 0;
			for (int j = i + 1; j > 0; j--) {
				string f = x.substr(i + 1 - j, j);
			//	cout << i << " " << f << " " << j << " " << s.substr(0, j) <<  endl;
				if (s.substr(0, j) == f) {
					to[i][c - 'A'] = j;
					break;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				dp[i][j][k] = -2e9;
				used[i][j][k] = false;
				p[i][j][k] = Item(-1, -1, -1);
			}
		}
	}
	//cout << to[0]['B' - 'A'] << endl;
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < t; k++) {
				if (k == 0) {
					if (dp[i][j][k] < 0 && a[i] != b[j]) {
						dp[i][j][k] = 0;
						p[i][j][k] = Item(-1, -1, -1);
						used[i][j][k] = false;
					}
					if (dp[i][j][k] < 1 && a[i] == b[j] && a[i] != s[0]) {
						dp[i][j][k] = 1;
						p[i][j][k] = Item(-1, -1, -1);
						used[i][j][k] = 1;
					}
				}
				else if (k == 1) {
					if (dp[i][j][k] < 1 && a[i] == b[j] && a[i] == s[0]) {
						dp[i][j][k] = 1;
						p[i][j][k] = Item(-1, -1, -1);
						used[i][j][k] = 1;
					}
				}
				if (dp[i][j][k] == -2e9) continue;
				//cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
				if (dp[i][j][k] >= dp[x][y][z]) {
					x = i, y = j, z = k;
				}
				if (i < (n - 1)) {
					if (dp[i + 1][j][k] < dp[i][j][k]) {
						dp[i + 1][j][k] = dp[i][j][k];
						used[i + 1][j][k] = false;
						p[i + 1][j][k] = Item(i, j, k);
					}
				}
				if (j < (m - 1)) {
					if (dp[i][j + 1][k] < dp[i][j][k]) {
						dp[i][j + 1][k] = dp[i][j][k];
						used[i][j + 1][k] = false;
						p[i][j + 1][k] = Item(i, j, k);
					}
				}
				if (i < (n - 1) && j < (m - 1)) {
					if (a[i + 1] == b[j + 1]) {
						int x = to[k][a[i + 1] - 'A'];
						if (x == t) continue;
						if (dp[i + 1][j + 1][x] < dp[i][j][k] + 1) {
							dp[i + 1][j + 1][x] = dp[i][j][k] + 1;
							used[i + 1][j + 1][x] = true;
							p[i + 1][j + 1][x] = Item(i, j, k);
						}
					}
				}
			}
		}
	}
	string ans = "";
	while (x != -1 && y != -1 && z != -1) {
		if (used[x][y][z])
			ans += a[x];
		Item f = p[x][y][z];
		x = f.a, y = f.b, z = f.c;
	}
	reverse(all(ans));
	if (ans.empty()) cout << 0 << endl;
	else cout << ans << endl;
	return;
}