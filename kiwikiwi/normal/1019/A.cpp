#include <bits/stdc++.h>
using namespace std;

int n, m, p, x, mark[3010];
vector<pair<int, int> > cost[3010], cst;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &p, &x);
		cost[p].push_back(make_pair(x, i));
		if (p != 1) cst.push_back(make_pair(x, i));
	}
	for (int i = 1; i <= m; i++)
		sort(cost[i].begin(), cost[i].end());
	sort(cst.begin(), cst.end());
	long long ans = 1ll << 60;
	for (int i = 1; i <= n; i++) {
		int par = cost[1].size();
		long long cc = 0;
		for (int j = 2; j <= m; j++) {
			int cnt = cost[j].size();
			for (auto x : cost[j]) {
				if (cnt < i) break;
				mark[x.second] = i;
				cnt--;
				par++;
				cc += x.first;
			}
		}
		for (auto x : cst) {
			if (par >= i) break;
			if (mark[x.second] != i) cc += x.first, par++;
		}
		ans = min(ans, cc);
	}
	printf("%lld\n", ans);
}