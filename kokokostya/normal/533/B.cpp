



#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

const int MX = 2e5 + 7;
int a[MX];
int p[MX];
vector<int> g[MX];

const long long INF = 1e18;
pair<long long, long long> dp[MX];

void dfs(int v) {
	for (int i : g[v])
		dfs(i);
	dp[v] = { a[v], 0 };
	long long sum = 0;
	long long del = INF;
	int cnt = 0;
	for (int i : g[v]) {
		if (dp[i].first > dp[i].second) {
			sum += dp[i].first;
			cnt++;
			del = min(del, dp[i].first - dp[i].second);
		}
		else {
			sum += dp[i].second;
			del = min(del, dp[i].second - dp[i].first);
		}
	}
	if (cnt % 2 == 1) {
		dp[v] = { max(a[v] + sum - del, sum), sum - del };
	}
	else {
		dp[v] = { a[v] + sum, sum };
	}
	
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int st = 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> a[i];
		p[i]--;
		if (p[i] >= 0)
			g[p[i]].push_back(i);
		else
			st = i;
	}
	dfs(st);
	cout << max(dp[st].first, dp[st].second);
	return 0;
}