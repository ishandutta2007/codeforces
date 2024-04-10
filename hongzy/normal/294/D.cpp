#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;

struct node {
	int x, y, dx, dy;
	bool operator < (const node &b) const {
		if(mp(x, y) == mp(b.x, b.y)) return mp(dx, dy) < mp(b.dx, b.dy);
		return mp(x, y) < mp(b.x, b.y);
	}
} st;

int n, m, sx, sy, cnt = 1;
map<node, bool> vis;
map<pii, bool> vis2;
char s[5];

ll dfs(node u) {
//	printf("[%d, %d]\n", u.x, u.y);
	int tx = u.dx == -1 ? u.x - 1 : n - u.x;
	int ty = u.dy == -1 ? u.y - 1 : m - u.y;
	int t = min(tx, ty);
	u.x += u.dx * t; u.y += u.dy * t;
	if(t == tx) u.dx *= -1;
	if(t == ty) u.dy *= -1;
	if(!vis2[mp(u.x, u.y)]) {
		vis2[mp(u.x, u.y)] = 1;
		if(++ cnt == n + m - 2) {
			return t;
		}
	}
	if(vis[u]) return -1;
	vis[u] = 1;
	ll ans = dfs(u);
	if(ans == -1) return -1;
	return t + ans;
}

int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d%s", &sx, &sy, s);
	s[0] = (s[0] == 'D' ? 1 : -1);
	s[1] = (s[1] == 'R' ? 1 : -1);
	vis[st = (node) {sx, sy, s[0], s[1]}] = 1;
	vis2[mp(sx, sy)] = 1;
	ll ans = dfs(st);
	printf("%lld\n", ans == -1 ? -1 : ans + 1);
	return 0;
}