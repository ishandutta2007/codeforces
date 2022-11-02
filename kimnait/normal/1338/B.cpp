#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
//#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int MXN = (int)1e6 + 7;
int dep[MXN];
vector<int> edge[MXN];
bool ck[MXN];
void dfs(int u, int pa, int dpt) {
	dep[u] = dpt;
	for (int v : edge[u]) {
		if (v == pa) continue ;
		dfs(v, u, dpt + 1);
	}
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int rt = 1;
	for (int i = 1; i <= n; i++)
		if (SZ(edge[i]) == 1) {
			ck[i] = true;
		}
	int ll = 1, rr = n - 1;
	for (int i = 1; i <= n; i++) {
		if (ck[i]) continue ;
		int cnt = 0;
		for (int v : edge[i]) {
			if (ck[v]) cnt++;
		}
		if (cnt) rr -= (cnt - 1);
	}
	dfs(rt, 0, 1);
	int pre = -1;
	for (int i = 1; i <= n; i++) {
		if (ck[i]) {
			if (pre == -1) pre = i;
			else if (dep[pre] % 2 != dep[i] % 2) {
				ll = 3; break ;
			}
		}
	}
	printf("%d %d\n", ll, rr);
	return 0;
}