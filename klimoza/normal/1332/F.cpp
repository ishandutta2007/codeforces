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
const ld eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
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

const int N = 3e5 + 7;
ll dp[N][3];
vector<int> g[N];

ll mul(ll a, ll b) {
	a %= mod; b %= mod;
	return a * b % mod;
}

void dfs(int v, int last = -1) {
	dp[v][0] = dp[v][1] = dp[v][2] = 1;
	for (int u : g[v]) {
		if (u == last) continue;
		dfs(u, v);
		dp[v][0] = mul(dp[v][0], 2 * dp[u][0] + 2 * dp[u][1] - dp[u][2] + mod);
		dp[v][1] = mul(dp[v][1], 2 * dp[u][0] + dp[u][1] - dp[u][2] + mod);
		dp[v][2] = mul(dp[v][2], dp[u][0] + dp[u][1] - dp[u][2] + mod);
	}
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	cout << (dp[0][0] + dp[0][1] - dp[0][2] - 1 + mod) % mod << endl;
	return;
}