#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 300005;
int n, q;
int tp, x;
int cnt[N];
int ans = 0;
int a[N], an, vis[N];
vector<int> g[N];

int main() {
	int la = 0;
	scanf("%d%d", &n, &q);
	while (q--) {
		scanf("%d%d", &tp, &x);
		if (tp == 1) {
			g[x].push_back(an);
			a[an++] = x;
			ans++;
		} else if (tp == 2) {
			for (int i = 0; i < g[x].size(); i++) {
				int v = g[x][i];
				if (vis[v]) continue;
				vis[v] = 1;
				ans--;
			}
			g[x].clear();
		} else {
			for (int v = la; v < x; v++) {
				if (vis[v]) continue;
				vis[v] = 1;
				ans--;
			}
			la = max(la, x);
		}
		printf("%d\n", ans);
	}
	return 0;
}