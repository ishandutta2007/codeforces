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

const int N = 200005;
const int inf = 0x3f3f3f3f;
int n, m;
vi g[N];

struct C {
	int x, y, id;
	void read(int id) {
		this->id = id;
		scanf("%d%d", &x, &y);
	}
	bool operator < (const C& c) const {
		return x < c.x;
	}
} c[N], p[N];

int ans[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) c[i].read(i);
	sort(c + 1, c + 1 + n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) p[i].read(i);
	sort(p + 1, p + 1 + m);
	int j = 1;
	for (int i = 1; i <= m; i++) {
		while (j <= n && c[j].x - c[j].y <= p[i].x) j++;
		g[j - 1].pb(i);
		if (j - 2 >= 0) g[j - 2].pb(i);
	}
	for (int i = 1; i <= n; i++) ans[i] = inf;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sz(g[i]); j++) {
			int k = g[i][j];
			int x = p[k].x, y = p[k].y;
			if ((x - c[i].x) * (x - c[i].x) + y * y <= c[i].y * c[i].y) {
				ans[c[i].id] = min(ans[c[i].id], p[k].id);
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == inf) ans[i] = -1;
		else cnt++;
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n");
	return 0;
}