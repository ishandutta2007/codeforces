#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000005;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
vector<int> g[N];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x, a; scanf("%d", &x);
		while (x--) {
			scanf("%d", &a);
			g[a].push_back(i);
		}
	}
	sort(g + 1, g + 1 + m);
	int f = 1, ans = 1;
	for (int i = 2; i <= m; i++) if (g[i] == g[i - 1]) ans = (1LL * ans * (++f)) % MOD; else f = 1;
	printf("%d\n", ans);
	return 0;
}