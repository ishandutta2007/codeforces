#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int cnt[maxn];
unsigned ll ans;
ll strange[maxn], strangesum[maxn];
vector<int> e[maxn];

int dfs(int v, int p = 0) {
	cnt[v] = 1;
	for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) {
		cnt[v] += dfs(e[v][i], v);
	}
	int ost = cnt[v];
	ll somesum = 0;
	for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) {
		ost -= cnt[e[v][i]];
		ans += 1LL * (cnt[v] - cnt[e[v][i]]) * (cnt[v] - cnt[e[v][i]] - 1) / 2 * cnt[e[v][i]] * (cnt[e[v][i]] - 1) / 2;
		//ans += 1LL * ost * (ost - 1) / 2 * cnt[e[v][i]] * (cnt[e[v][i]] - 1) / 2;
		ans += 1LL * (cnt[v] - cnt[e[v][i]]) * strangesum[e[v][i]];
		strangesum[v] += strangesum[e[v][i]];
		strangesum[v] += 1LL * cnt[e[v][i]] * (cnt[e[v][i]] - 1) / 2 * (cnt[v] - cnt[e[v][i]]);
		somesum += 1LL * cnt[e[v][i]] * (cnt[e[v][i]] - 1) / 2;
	}

	for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) {
		somesum -= 1LL * cnt[e[v][i]] * (cnt[e[v][i]] - 1) / 2;
		ans -= somesum * cnt[e[v][i]] * (cnt[e[v][i]] - 1) / 2;
	}

	return cnt[v];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs(1);
	cout << 2 * ans << endl;

	return 0;
}