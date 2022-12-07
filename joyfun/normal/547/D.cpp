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
int n;

struct Point {
	int x, y, id;
	void read(int id) {
		scanf("%d%d", &x, &y);
		this->id = id;
	}
} p[N];

bool cmpx(Point a, Point b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool cmpy(Point a, Point b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

vi g[N];
int col[N];

void dfs(int u, int c) {
	if (col[u] != -1) return;
	col[u] = c;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		dfs(v, c^1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) p[i].read(i);
	sort(p, p + n, cmpx);
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j < n && p[i].x == p[j].x) j++;
		for (int k = i; k < j - 1; k += 2) {
			g[p[k].id].pb(p[k + 1].id);
			g[p[k + 1].id].pb(p[k].id);
		}
		i = j - 1;
	}
	sort(p, p + n, cmpy);
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j < n && p[i].y == p[j].y) j++;
		for (int k = i; k < j - 1; k += 2) {
			g[p[k].id].pb(p[k + 1].id);
			g[p[k + 1].id].pb(p[k].id);
		}
		i = j - 1;
	}
	memset(col, -1, sizeof(col));
	for (int i = 0; i < n; i++)
		if (col[i] == -1) dfs(i, 0);
	for (int i = 0; i < n; i++) printf("%c", col[i] ? 'r' : 'b');
	return 0;
}