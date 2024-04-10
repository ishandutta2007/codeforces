#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> lk[N], nlk[N];
int dp[N], q[N], ou[N];

int main() {
#ifdef kcz
	freopen("1.in", "r", stdin); //freopen("1.out","w",stdout);
#endif
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int t = 0;
		for (int i = 1; i <= n; ++i) nlk[i].clear();
		for (int i = 1; i <= n; ++i) {
			lk[i].clear();
			dp[i] = 1;
			int k;
			scanf("%d", &k);
			lk[i].resize(k);
			for (int j = 0; j < k; ++j) {
				scanf("%d", &lk[i][j]);
				nlk[lk[i][j]].push_back(i);
			}
			ou[i] = k;
			if (k == 0) q[++t] = i;
		}
		for (int h = 1; h <= t; ++h) {
			int x = q[h];
			for (auto y: lk[x]) {
				dp[x] = max(dp[x], y > x ? dp[y] + 1 : dp[y]);
			}
			for (auto y: nlk[x]) {
				if (!--ou[y]) q[++t] = y;
			}
		}
		if (t < n)
			puts("-1");
		else
			cout << *max_element(dp + 1, dp + n + 1) << endl;
	}
}