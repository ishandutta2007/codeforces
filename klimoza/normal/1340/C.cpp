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

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-7;
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

const int N = 1e4 + 7;
const int K = 1e3 + 7;

bool used[N][K];

int d[N];

int cnt = 1;
int c1[N * K];
int c2[N * K];
int nc1[N * K];
int nc2[N * K];
int kek[N];

int k;
int m;

void bfs() {
	c1[0] = 0;
	c2[0] = 0;
	used[0][0] = true;
	int x, y;
	for (int i = 1; cnt ; i++) {
		int ns = 0;
		for (int j = 0; j < cnt; j++) {
			if (i & 1) {
				x = c1[j];
				y = c2[j];
			}
			else {
				x = nc1[j];
				y = nc2[j];
			}
			//cout << x << " " << y << endl;
			if (x && y + d[x] <= k && !used[x - 1][y + d[x]]) {
				used[x - 1][y + d[x]] = true;
				if (x != 1 && y + d[x] == k) {
					kek[x - 1] = i;
					if (i & 1) {
						nc1[ns++] = x - 1;
						nc2[ns - 1] = 0;
					}
					else {
						c1[ns++] = x - 1;
						c2[ns - 1] = 0;
					}
				}
				else if(y + d[x] != k){
					if (i & 1) {
						c1[cnt++] = x - 1;
						c2[cnt - 1] = y + d[x];
					}
					else {
						nc1[cnt++] = x - 1;
						nc2[cnt - 1] = y + d[x];
					}
				}
			}
			if (x < (m - 1) && y + d[x + 1] <= k && !used[x + 1][y + d[x + 1]]) {
				used[x + 1][y + d[x + 1]] = true;
				if (y + d[x + 1] == k) {
					kek[x + 1] = i;
					if (i & 1) {
						nc1[ns++] = x + 1;
						nc2[ns - 1] = 0;
					}
					else {
						c1[ns++] = x + 1;
						c2[ns - 1] = 0;
					}
				}
				else if(y + d[x + 1] != k){
					if (i & 1) {
						c1[cnt++] = x + 1;
						c2[cnt - 1] = y + d[x + 1];
					}
					else {
						nc1[cnt++] = x + 1;
						nc2[cnt - 1] = y + d[x + 1];
					}
				}
			}
		}
		cnt = ns;
	}
}

void solve() {
	int n; cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> d[i];
	sort(d ,d + m);
	int g, r; cin >> g >> r;
	for (int i = m - 1; i > 0; i--)
		d[i] = d[i] - d[i - 1];
	k = g;
	bfs();
	int s = 0;
	ll ans = inf;
	for (int i = m - 1; i >= 0; i--) {
		if (!used[i][0] && !used[i][k]) {
			s += d[i];
			if (s > g) break;
			continue;
		}
		//cout << i << endl;
		ans = min(ans, kek[i] * 1ll * (g + r) + s);
		s += d[i];
		if (s > g) break;
	}
	if (ans == inf) cout << -1 << endl;
	else cout << ans << endl;
	return;
}