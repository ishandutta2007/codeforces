#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 3005;
int n, m;

struct edge {
	int u, v, l, r;
	void read() {
		scanf("%d%d%d%d", &u, &v, &l, &r);
	}
	bool operator < (const edge& c) const {
		return r > c.r;
	}
} e[N];

int fa[N];
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) e[i].read();
	sort(e + 1, e + 1 + m);
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) fa[j] = j;
		for (int j = 1; j <= m; j++) {
			if (e[j].l > e[i].l) continue;
			int u = find(e[j].u);
			int v = find(e[j].v);
			if (u != v) fa[u] = v;
			if (find(1) == find(n)) {
				ans = max(ans, e[j].r - e[i].l + 1);
				break;
			}
		}
	}
	if (ans == 0) printf("Nice work, Dima!\n");
	else printf("%d\n", ans);
	return 0;
}