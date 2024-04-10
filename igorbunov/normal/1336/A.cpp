#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
using namespace std;

#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

vector<int> g[300000];
vector<int> dp(300000);
vector<int> gl(300000);

vector<int> ans;

void dfs(int v, int p = -1) {
	for (auto u: g[v]) {
		if (u != p) {
			gl[u] = gl[v] + 1;
			dfs(u, v);
			dp[v] += dp[u];
		}
	}
	ans.push_back(gl[v] - dp[v]);
	dp[v]++;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	sort(ans.rbegin(), ans.rend());
	int val = 0;
	for (int i = 0; i < k; i++) {
		val += ans[i];
	}
	cout << val;
}