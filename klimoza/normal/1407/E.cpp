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

mt19937 mrand(random_device{}());

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

const int N = 5e5 + 2;

vector<pair<int, int>> g[N];

int h[N][2];

int ans[N];
int dp[N];
bool used[N];

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		g[i].clear();
		ans[i] = -1;
		dp[i] = inf0;
		h[i][0] = h[i][1] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b, t; cin >> a >> b >> t; a--; b--;
		g[b].push_back({ a, t });
	}
	vector<int> cr, nn;
	cr = { n - 1 };
	dp[n - 1] = 0;
	used[n - 1] = true;
	ans[n - 1] = 0;
	while (!cr.empty()) {
		nn.clear();
		for (int i : cr) {
			for (auto u : g[i]) {
				if (used[u.first]) continue;
				h[u.first][u.second] = 1;
				if (h[u.first][0] == h[u.first][1]) {
					dp[u.first] = 1 + dp[i];
					ans[u.first] = u.second;
					used[u.first] = true;
					nn.push_back(u.first);
				}
				else if(ans[u.first] == -1){
					ans[u.first] = u.second ^ 1;
				}
			}
		}
		swap(nn, cr);
	}
	if (dp[0] == inf0)
		cout << -1 << endl;
	else
		cout << dp[0] << endl;
	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) cout << 0;
		else cout << ans[i];
	}
	cout << endl;
	return;
}