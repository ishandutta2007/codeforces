// Hydro submission #62da273989531d052a1dc330@1658464057848
#include<cstdio>
#include<vector>
#include<algorithm>
using std::sort;

int n, m, f[100010], ans/*-1at least one, 0nong, 1any*/[100010];

namespace graph { //Tarjan
	using std::min;
	using std::vector;

	struct node {
		int to, id;
	};
	static int nowtime, dfn[100010], low[100010];
	vector < node > e[100010];
	struct node1 {
		int from, to, v, id;
		bool operator < (const node1 & a) const {
			return v < a.v;
		}
	}
	edge[100010];

	inline void addedge(int from, int to, int id) { //
		e[from].push_back(node{to, id}),
		e[to].push_back(node{from, id});
	}

	void tarjan(int now, int faid) { //faidnow
		low[now] = dfn[now] = nowtime++;
		for (register int i = 0; i < (int) e[now].size(); ++i) {
			if (e[now][i].id == faid)
				continue;
			if (!dfn[e[now][i].to]) {
				tarjan(e[now][i].to, e[now][i].id),
					low[now] = min(low[now], low[e[now][i].to]);
				if (low[e[now][i].to] > dfn[now])
					ans[e[now][i].id] = 1;
			} else
				low[now] = min(low[now], dfn[e[now][i].to]);
		}
	}
}

inline int getf(int x) {
	return f[x] = x == f[x] ? x : getf(f[x]);
}

inline void init() {
	scanf("%d%d", & n, & m);
	for (register int i = 1; i <= n; ++i)
		f[i] = i;
	for (register int i = 1; i <= m; ++i)
		scanf("%d%d%d", & graph::edge[i].from, & graph::edge[i].to, & graph::edge[i].v),
		graph::edge[i].id = i;
	sort(graph::edge + 1, graph::edge + m + 1);
}

inline void work() {
	int j;
	for (register int i = 1; i <= m; i = j) {
		j = i + 1;
		while (j <= m && graph::edge[i].v == graph::edge[j].v) //[)
			++j;
		for (register int l = i; l < j; ++l) {
			int x = getf(graph::edge[l].from), y = getf(graph::edge[l].to);
			if (x == y)   //
				continue; //ans = none
			graph::addedge(x, y, graph::edge[l].id), //
			graph::dfn[x] = graph::dfn[y] = 0, //dfn0
			ans[graph::edge[l].id] = -1; //ansat least one
		}
		for (register int l = i; l < j; ++l) {
			int x = getf(graph::edge[l].from), y = getf(graph::edge[l].to);
			if (x == y || graph::dfn[x]) //Tarjan
				continue;
			graph::nowtime = 0,
			graph::tarjan(x, -1); //Tarjan
		}
		for (register int l = i; l < j; ++l) {
			int x = getf(graph::edge[l].from), y = getf(graph::edge[l].to);
			if (x == y)
				continue;
			graph::e[x].clear(), //
			graph::e[y].clear(),
			f[x] = y;
		}
	}
}

int main(void) {
	init();
	work();
	for (register int i = 1; i <= m; ++i)
		if (ans[i] == 1) puts("any");
		else if (ans[i] == 0) puts("none");
		else puts("at least one");
	return 0;
}