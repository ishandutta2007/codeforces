#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000005;
typedef pair<int, int> pii;
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
map<int, int> pre;
int n, a[N], p[N];
vector<pii> g[N];

#define lowbit(x) (x&(-x))
int bit[N];

void add(int x, int v) {
	while (x <= n) {
		bit[x] ^= v;
		x += lowbit(x);
	}
}

void add(int l, int r, int v) {
	add(l, v);
	add(r + 1, v);
}

int get(int x) {
	int ans = 0;
	while (x) {
		ans ^= bit[x];
		x -= lowbit(x);
	}
	return ans;
}

int ans[N];

int main() {
	while (~scanf("%d", &n)) {
		pre.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			p[i] = pre[a[i]];
			pre[a[i]] = i;
			g[i].clear();
			bit[i] = 0;
		}
		int q;
		scanf("%d", &q);
		int l, r;
		for (int i = 0; i < q; i++) {
			scanf("%d%d", &l, &r);
			g[r].push_back(mp(l, i));
		}
		for (int i = 1; i <= n; i++) {
			if (p[i]) add(1, p[i], a[i]);
			for (int j = 0; j < g[i].size(); j++) {
				ans[g[i][j].se] = get(g[i][j].fi);
			}
		}
		for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
	}
	return 0;
}