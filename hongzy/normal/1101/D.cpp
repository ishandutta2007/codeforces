#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 2e5 + 10;

int n, ans;
vector<int> G[N], p[N], f[N], g[N];

void solve(int i, int x) {
	for(int y = 2; y * y <= x; y ++) {
		if(x % y == 0) {
			for(; x % y == 0; x /= y) ;
			p[i].push_back(y);
			f[i].push_back(0);
			g[i].push_back(0);
		}
	}
	if(x > 1) {
		p[i].push_back(x);
		f[i].push_back(0);
		g[i].push_back(0);
	}
}

void dp(int u, int fa = 0) {
	for(int v : G[u]) if(v != fa) {
		dp(v, u);
		for(int i = 0; i < p[u].size(); i ++)
			for(int j = 0; j < p[v].size(); j ++) {
				if(p[u][i] == p[v][j]) {
					if(f[v][j] + 1 > f[u][i]) {
						g[u][i] = f[u][i];
						f[u][i] = f[v][j] + 1; 
					} else if(f[v][j] + 1 > g[u][i])
						g[u][i] = f[v][j] + 1;
				}
			}
	}
	for(int i = 0; i < p[u].size(); i ++)
		ans = max(ans, f[u][i] + g[u][i]);
}
int main() {
	bool fail = 1;
	scanf("%d", &n);
	for(int x, i = 1; i <= n; i ++) {
		scanf("%d", &x);
		if(x > 1) fail = 0;
		solve(i, x);
	}
	if(fail) return puts("0"), 0;
	int u, v;
	for(int i = 1; i < n; i ++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dp(1, 0);
	printf("%d\n", ans + 1);
	return 0;
}