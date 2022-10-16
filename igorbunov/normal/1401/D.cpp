#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
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


//#pragma GCC_OPTIMIZE("ofast")
using namespace std;


#define int long long
#define endl "\n"

vector<int> g[100000];
vector<int> dp(100000);
int n;

int dfs(int v, int p = -1) {
	dp[v] = 1;
	for (auto u: g[v]) {
		if (u == p) {
			continue;
		}
		dp[v] += dfs(u, v);
	}
	return dp[v];
}

vector<int> cnt;

void dfs1(int v, int p = -1) {
	for (auto u: g[v]) {
		if (u == p) {
			continue;
		}
		cnt.push_back(dp[u] * (n - dp[u]));
		dfs1(u, v);
	}
}

int MOD = 1000000007LL;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		g[i].clear();
		dp[i] = 0;
	}
	cnt.clear();
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	dfs1(0);
	int m;
	cin >> m;
	vector<int> arr(m);
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	sort(cnt.begin(), cnt.end());
	sort(arr.begin(), arr.end());
	while (arr.size() > cnt.size()) {
		arr[arr.size() - 2] *= arr[arr.size() - 1];
		arr.pop_back();
		arr[arr.size() - 1] %= MOD;
	}
	int ind = arr.size() - 1;
	int ans = 0;
	for (int i = cnt.size() - 1; i >= 0; i--) {
		cnt[i] %= MOD;
		if (ind < 0) {
			ans += cnt[i];
			ans %= MOD;
			continue;
		} else {
			ans += (cnt[i] * arr[ind]) % MOD;
			ans %= MOD;
			ind--;
		}
	}
	cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}