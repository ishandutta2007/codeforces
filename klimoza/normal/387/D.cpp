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

const int N = 501;

int px[N];

vector<int> g[N];

bool used[N];
vector<int> ng[N];

bool dfs(int v) {
	used[v] = true;
	for (int u : ng[v]) {
		if (px[u] == -1 || (!used[px[u]] && dfs(px[u]))) {
			px[u] = v;
			return true;
		}
	}
	return false;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
	}
	int ans = 2e9;
	for (int i = 0; i < n; i++) {
		int tot = m - g[i].size() + (n - g[i].size());
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			bool fl = false;
			for (int k : g[j])
				if (k == i) {
					tot--;
					fl = true;
				}
			if (!fl)
				tot++;
		}
		for (int j = 0; j < n; j++)
			ng[j].clear();
		fill(px, px + n, -1);
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			for (int k : g[j]) {
				if (k == i) continue;
				ng[j].push_back(k);
			}
		}
		fill(used, used + n, false);
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			dfs(j);
			fill(used, used + n, false);
		}
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			//cout << j << " " << px[j] << " kek\n";
			if (i != j && px[j] != -1)
				cnt++;
		}
		//cout << tot << " " << cnt << endl;
		tot += (n - 1 - cnt) - cnt;
		ans = min(ans, tot);
	}
	cout << ans << endl;
	return;
}