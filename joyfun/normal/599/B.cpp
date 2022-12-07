#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, m;
int f[N], b[N];
vector<int> g[N];
int ans[N];

int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &f[i]);
			g[f[i]].push_back(i);
		}
		int f = 2;
		for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= m; i++) {
			if (g[b[i]].size() == 0) {
				f = 0;
				break;
			}
			if (g[b[i]].size() >= 1) {
				if (g[b[i]].size() > 1)
					f = 1;
				ans[i] = g[b[i]].back();
			}
		}
		if (f == 2) {
			printf("Possible\n");
			for (int i = 1; i <= m; i++) printf("%d ", ans[i]); printf("\n");
		} else if (f == 1) printf("Ambiguity\n");
		else printf("Impossible\n");
	}
	return 0;
}