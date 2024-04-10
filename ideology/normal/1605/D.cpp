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
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 200010;

int ans[N];
vector<int> cand[20];
vector<int> G[N];
bool vis[N];

void dfs(int u, int p) {
	for (int v : G[u]) if (v != p) { vis[v] = !vis[u]; dfs(v, u); }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int rep = 1; rep != n; ++rep) {
			int u, v; cin >> u >> v;
			G[u].push_back(v); G[v].push_back(u);
		}
		dfs(1, 0);
		int x = count(vis + 1, vis + n + 1, 0);
		int fa = 0;
		for (int i = 1; i <= n; ++i) {
			cand[fa].push_back(i);
			if (!(i & (i + 1))) ++fa;
		}
		int rest = x;
		vector<int> X, Y;
		for (int i = fa; i >= 0; --i) if (rest >= cand[i].size()) {
			rest -= cand[i].size();
			X.insert(X.end(), cand[i].begin(), cand[i].end()); cand[i].clear();
		} else {
			Y.insert(Y.end(), cand[i].begin(), cand[i].end()); cand[i].clear();
		}
		for (int i = 1; i <= n; ++i) if (vis[i] == 0) {
			ans[i] = X.back(); X.pop_back();
		} else {
			ans[i] = Y.back(); Y.pop_back();
		}
		for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];

		for (int i = 1; i <= n; ++i) G[i].clear();
	}

	return 0;
}