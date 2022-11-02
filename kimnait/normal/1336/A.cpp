#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define MP  make_pair
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
//#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int N = (int)2e5 + 7;
vector<int> edge[ N ];
int dep[ N ], prt[ N ], deg[ N ];
int val[ N ];
void dfs(int u, int pa, int dpt) {
	dep[u] = dpt;
	prt[u] = pa;
	val[u] = 1;
	for (int v : edge[u]) {
		if (v == pa) continue ;
		dfs(v, u, dpt + 1);
		deg[u]++;
		val[u] += val[v];
	}
}
int main() {
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1, 0, 1);
	set<PII> st;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			st.insert(MP(dep[i] - 1, i));
		}
	}
	long long ans = 0;
	for (int i = 1; i <= k; i++) {
		PII x = *(--st.end());
		st.erase(--st.end());
		ans += x.first;
		int v = x.second;
		deg[ prt[v] ]--;
		int p = prt[v];
		if (!deg[p]) {
			st.insert(MP(dep[p]-val[p], p));
		}
	}
	printf("%lld\n", ans);
	return 0;
}