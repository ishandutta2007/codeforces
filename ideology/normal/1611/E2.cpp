#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int P = 1000000007;

int norm(int x) { return x >= P ? x - P : x; }
void add(int& x, int y) { if ((x += y) >= P) x -= P; }
void sub(int& x, int y) { if ((x -= y) < 0) x += P; }

int mpow(int x, int k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = x * (ull)ret % P;
	return ret;
}

const int _ = 200010;

vector<int> G[_];
bool vis[_], win[_];
int dep[_], bad[_];

int ans;

void dfs(int u, int p) {
	if (vis[u]) {
		bad[u] = 0; return;
	}
	for (int v : G[u]) if (v != p) {
		dep[v] = dep[u] + 1;
		dfs(v, u);
		bad[u] = min(bad[u], bad[v] + 1);
	}
	if (bad[u] > dep[u]) win[u] = true;
}

void dfs2(int u, int p) {
	if (!win[u]) { ++ans; return; }
	if (u != 1 && G[u].size() == 1) { ans = -1; return; }
	for (int v : G[u]) if (v != p) {
		dfs2(v, u);
		if (ans == -1) return;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		while (K--) { int xi; cin >> xi; vis[xi] = true; }
		for (int rep = 1; rep != N; ++rep) {
			int u, v; cin >> u >> v;
			G[u].push_back(v); G[v].push_back(u);
		}
		fill(bad + 1, bad + N + 1, 1e9);
		fill(win + 1, win + N + 1, false);
		ans = 0;
		dfs(1, 1);
		dfs2(1, 1);
		cout << ans << '\n';
		fill(vis + 1, vis + N + 1, false);
		for (int i = 1; i <= N; ++i) G[i].clear();
	}

	return 0;
}