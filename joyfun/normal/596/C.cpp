#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 100005;

struct Point {
	int x, y;
	void read() {
		scanf("%d%d", &x, &y);
		x++; y++;
	}
	bool operator < (const Point& c) const {
		return x < c.x;
	}
} p[N];
int w[N];

int n;
vector<Point> g[N* 4];
vector<int> id[N], vis[N];
Point ans[N];

int main() {
	scanf("%d", &n);
	int r = 0, c = 0;
	for (int i = 0; i < n; i++) {
		p[i].read();
		r = max(r, p[i].x);
		c = max(c, p[i].y);
		g[p[i].y - p[i].x + 200000].push_back(p[i]);
	}
	for (int i = 0; i < 4 * N; i++) {
		sort(g[i].begin(), g[i].end());
		reverse(g[i].begin(), g[i].end());
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
		w[i] += 200000;
	}
	int f = 1;
	for (int i = 0; i < N; i++) {
		id[i].push_back(0);
		vis[i].push_back(0);
	}
	for (int i = 0; i < N; i++) {
		id[0].push_back(0);
		vis[0].push_back(0);
	}
	for (int i = 0; i < n; i++) {
		id[p[i].x].push_back(0);
		vis[p[i].x].push_back(0);
	}
	for (int i = 0; i < n; i++) {
		if (g[w[i]].size() == 0) {
			f = 0;
			break;
		}
		Point sb = g[w[i]].back();
		id[sb.x][sb.y] = i + 1;
		vis[sb.x][sb.y] = 1;
		ans[i] = sb;
		g[w[i]].pop_back();
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < id[i].size(); j++) {
			if (!vis[i][j]) continue;
			int Max = max(id[i - 1][j], id[i][j - 1]);
			if (Max >= id[i][j]) {
				f = 0;
			}
			id[i][j] = max(Max, id[i][j]);
		}
	}
	if (f) {
		printf("YES\n");
		for (int i = 0; i < n; i++) printf("%d %d\n", ans[i].x - 1, ans[i].y - 1);
	} else printf("NO\n");
	return 0;
}