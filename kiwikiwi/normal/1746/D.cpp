#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 223456;

int n, k, val[maxn];
map<int, ll> dp[maxn];
vector<int> son[maxn];

ll calc(int x, int k) {
	if (dp[x].count(k)) return dp[x][k];
	ll ans = (ll)val[x] * k;
	if (son[x].empty()) {
		return dp[x][k] = ans;
	}
	int m = son[x].size();
	vector<ll> gt;
	for (auto v : son[x]) {
		ans += calc(v, k / m);
		if (k % m != 0)
			gt.push_back(calc(v, k / m + 1) - calc(v, k / m));
	}
	if (k % m != 0) {
		sort(gt.rbegin(), gt.rend());
		for (int i = 0; i < k % m; i++)
			ans += gt[i];
	}
	return dp[x][k] = ans;
}
void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		son[i].clear();
		dp[i].clear();
	}
	for (int i = 2; i <= n; i++) {
		int p;
		scanf("%d", &p);
		son[p].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val[i]);
	}
	printf("%lld\n", calc(1, k));
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		solve();
	}
}