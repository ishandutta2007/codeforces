#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define pb push_back

const int N = 2e5 + 10;

int n, x, y, ans;
vector<int> G[N];
bool tag[N];

void dfs(int u, int fa = 0) {
	for(int v : G[u]) if(v != fa) dfs(v, u);
	int cnt = 0;
	for(int v : G[u]) if(v != fa) cnt += tag[v];
	if(cnt == 0) {
		tag[u] = 1;
	}
	if(cnt == 1) {
		tag[u] = 1; ans ++;
	}
	if(cnt >= 2) {
		tag[u] = 0; ans += 2;
	}
}

int main() {
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 1; i < n; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].pb(v); G[v].pb(u);
	}
	if(x >= y) {
		bool fl = 0;
		for(int i = 1; i <= n; i ++) {
			if(G[i].size() == n - 1) {
				fl = 1; break ;
			}
		}
		printf("%I64d\n", fl ? y * (n - 2ll) + x : y * (n - 1ll));
		return 0;
	}
	dfs(1);
	printf("%I64d\n", ans * 1ll * x + (n - 1ll - ans) * y);
	return 0;
}