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

map<pair<int, int>, int> id;
const int N = 5e3 + 8;

vector<int> g[N];
int used[N];
int ans[N];
bool fl = false;

void dfs(int v) {
	used[v] = 1;
	for (int u : g[v]) {
		if (used[u] == 1) {
			ans[id[{v, u}]] = 2;
			fl = true;
		}
		else if (used[u] == 2) {
			ans[id[{v, u}]] = 1;
		}
		else {
			ans[id[{v, u}]] = 1;
			dfs(u);
		}
	}
	used[v] = 2;
}


void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		id[{a, b}] = i;
		g[a].push_back(b);
	}
	fill(used, used + N, 0);
	for (int i = 0; i < n; i++) {
		if (!used[i]) dfs(i);
	}
	cout << 1 + fl << endl;
	for (int i = 0; i < m; i++) cout << ans[i] << " ";
}