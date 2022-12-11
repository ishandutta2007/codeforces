#include <set>
#include <cstdio>
using namespace std;
const int N = 505000;
set<int> ed[N], S[N];
int id[N], rt[N], p[N], q[N], T, m, n;
void work(void) {
	scanf ("%d%d", &n, &m);
	for (int i = 1;i <= n; ++i) ed[i].clear(), id[i] = 0;
	for (int i = 1, x, y;i <= m; ++i)
		scanf ("%d%d", &x, &y), ed[x].insert(y), ed[y].insert(x);
	int all = 0, cnt = 0;
	for (int i = 1, to;i <= n; ++i) {
		if (ed[i].size() == n - 1) { p[i] = q[i] = ++all; continue; }
		if (id[i]) continue;
		ed[i].insert(n + (to = 0));
		for (auto y : ed[i])
			if (y != (to += (i == to + 1) + 1)) break;
		auto mk = [&](int x, int y) {
			rt[id[x] = id[y] = ++cnt] = x;
			S[cnt].insert(x), S[cnt].insert(y);
		};
		if (!id[to]) { mk(i, to); continue; }
		int ak = id[to];
		if (S[ak].size() == 2 || rt[ak] == to) S[ak].insert(i), rt[id[i] = ak] = to;
		else S[ak].erase(to), mk(i, to);
	}
	for (int i = 1;i <= cnt; ++i) {
		p[rt[i]] = ++all;
		for (auto t: S[i]) 
			if (t != rt[i]) q[t] = all, p[t] = ++all;
		q[rt[i]] = all, S[i].clear(), rt[i] = 0;
	}
	for (int i = 1;i <= n; ++i) printf("%d%c", p[i], " \n"[i == n]);
	for (int i = 1;i <= n; ++i) printf("%d%c", q[i], " \n"[i == n]);
}

int main() {
	for (scanf ("%d", &T); T; T--) work();
	return 0;
}