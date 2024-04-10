#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define MP  make_pair
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = 998244353;
const LL INF = 1e18;
const int N = (int)1e5 + 7;
const long double PI = acos(-1);
vector<int> edge[ N ];
int cntp;
PII ans[ N*10 ];
int dfs(int u, int pa, int c) {
	int sz = SZ(edge[u]);
	bool ck = false;
	ans[++cntp] = {u, c};
	for (int v : edge[u]) {
		if (v == pa) continue ;
		if (!ck && c >= sz) {
			ck = true;
			c -= sz;
			ans[++cntp] = {u, c};
		}
		c = dfs(v, u, c + 1);
		ans[++cntp] = {u, c};
	}
	if (!ck && c >= sz) {
		ck = true;
		c -= sz;
		ans[++cntp] = {u, c};
	}
	return c + 1;
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1, 0, 0);
	cntp--;
	printf("%d\n", cntp);
	for (int i = 1; i <= cntp; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}