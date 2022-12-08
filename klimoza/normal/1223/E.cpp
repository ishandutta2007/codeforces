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

#define int long long

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

const int N = 5e5 + 7;

vector<pair<ll, ll>> g[N];
int n, k;
ll dp[N][2];

void dfs(int v, int last = -1) {
	dp[v][0] = dp[v][1] = 0;
	ll ans = 0;
	for (pair<ll, ll> u : g[v]) {
		if (u.first == last) continue;
		dfs(u.first, v);
		ans += dp[u.first][0];
	}
	sort(all(g[v]), [](pair<ll, ll> x, pair<ll, ll> y) {return (dp[x.first][1] + x.second - dp[x.first][0]) > (dp[y.first][1] + y.second - dp[y.first][0]); });
	int cnt = 0;
	ll f1 = -1, f2 = -1;
	if (k == 1) f2 = ans;
	for (auto u : g[v]){
		if (u.first == last) continue;
		ll an1 = ans;
		//cout << u.first << " " << v << " " << u.second << endl;
		ans += dp[u.first][1] + u.second - dp[u.first][0];
		cnt++;
		if (ans < an1) {
			ans = an1;
			break;
		}
		if ((cnt == (k - 1))) {
			f2 = ans;
		}
		if (cnt == k) {
			f1 = ans;
			break;
		}
	}
	//if (v == 1) cout << "LOOL " << ans << endl;
	if (f2 == -1) f1 = f2 = ans;
	else if (f1 == -1) f1 = ans;
	dp[v][0] = f1;
	dp[v][1] = f2;
}

//PLEASE

void solve() {
	int q; cin >> q;
	while (q--) {
		cin >> n >> k;
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		fill(g, g + n, vector<pair<ll, ll>>());
		for (int i = 1; i < n; i++) {
			ll u, v; cin >> u >> v; u--; v--;
			ll w; cin >> w;
			g[u].push_back({ v, w });
			g[v].push_back({ u, w });
		}
		dfs(0);
		//for (int i = 0; i < n; i++) cout << dp[i][0] << " " << dp[i][1] << endl;
		cout << dp[0][0] << endl;
	}
}