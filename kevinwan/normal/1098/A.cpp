#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
const int mn = 1e5 + 10;
vector<int> g[mn];
int s[mn],a[mn];
void dfs(int x, int p) {
	int sm = 0x3f3f3f3f;
	for (int y : g[x]) {
		if (y == p)continue;
		sm = min(sm, s[y]);
	}
	if (s[x] == -1) {
		if (sm == 0x3f3f3f3f)s[x] = s[p];
		else s[x] = sm;
	}
	a[x] = s[x] - s[p];
	for (int y : g[x]) {
		if (y == p)continue;
		dfs(y, x);
	}
}
int main() {
	int n, i,x;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)scanf("%d", &x), g[x].push_back(i);
	for (i = 1; i <= n; i++)scanf("%d", s + i);
	dfs(1, 0);
	ll ans = 0;
	for (i = 1; i <= n; i++) {
		ans += a[i];
		if (a[i] < 0) {
			printf("-1");
			return 0;
		}
	}
	printf("%lld", ans);
}