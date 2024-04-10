#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std; 

const int maxn = -1;
const int inf = 1e9;

int dp[301][1 << 9];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		vector<int> l(n);
		for (int i = 0; i < n; i++) cin >> l[i];
		vector<int> c(n);
		for (int i = 0; i < n; i++) cin >> c[i];

		int ans = 2e9;
		for (int i = 0; i < n; i++) {
			vector<int> pr;
			int x = l[i];
			for (int i = 2; i * i <= x; i++) {
				if (x % i == 0) {
					while (x % i == 0) x /= i;
					pr.push_back(i);
				}
			}
			if (x > 1) pr.push_back(x);

			vector<pair<int, int> > b;
			for (int j = 0; j < n; j++) {
				int cmask = 0;
				for (int k = 0; k < (int)pr.size(); k++) if (l[j] % pr[k] == 0) cmask |= 1 << k;
				b.push_back(make_pair(cmask, c[j]));
			}

			int m = pr.size();
			memset(dp, 63, sizeof(dp));
			dp[0][(1 << m) - 1] = c[i];
			for (int i = 0; i < n; i++) {
				for (int mask = 0; mask < 1 << m; mask++) {
					dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask]);
					dp[i + 1][mask & b[i].first] = min(dp[i + 1][mask & b[i].first], dp[i][mask] + b[i].second);
				}
			}
			if (dp[n][0] < ans) ans = dp[n][0];
		}
		if (ans > inf) ans = -1;
		cout << ans << endl;
	}

	return 0;
}