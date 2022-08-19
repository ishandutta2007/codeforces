#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 666;
int n, col[maxN];
bool vis[maxN];
vector<int> e[maxN];
bool g[maxN][maxN];
int cnt;
int query(vector<int> s) {
	cnt++;
	int c = s.size();
	printf("? %d\n", c);
	for (int i = 0; i < c; i++) {
		printf("%d", s[i]);
		if (i != c - 1) putchar(' ');
	}
	puts("");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

bool existEdge(int u, vector<int> s) {
	s.push_back(u);
	return query(s) > 0;
}
int findEdge(int u, vector<int> s) {
	int l = 0, r = s.size() + 1;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		vector<int> ask;
		ask.push_back(u);
		for (int i = 0; i < mid; i++)
			ask.push_back(s[i]);
		if (query(ask) == 0)
			l = mid;
		else
			r = mid;
	}
	if (l >= s.size()) return -1;
	else return s[l];
}
void addEdge(int u, int v) {
	e[u].push_back(v);
	e[v].push_back(u);
}

int root, cyc[maxN];
void dfs(int u, int par, int dep) {
	cyc[dep] = u;
	for (auto v : e[u]) {
		if (v != par) {
			if (v == root) {
				printf("N %d\n", dep + 1);
				for (int i = 0; i <= dep; i++) {
					printf("%d ", cyc[i]);
				}
				puts("");
				exit(0);
			}
			dfs(v, u, dep + 1);
		}
	}
}

void findCycle(int u) {
	root = u;
	dfs(u, 0, 0);
}

int main() {
	scanf("%d", &n);
	vector<int> cur;
	cur.push_back(1);
	vis[1] = 1;
	col[1] = 0;
	int curedge = query(cur);
	for (int T = 2; T <= n; T++) {
		vector<int> rem;
		for (int i = 1; i <= n; i++)
			if (vis[i] == 0) rem.push_back(i);
		int l = 0, r = rem.size(); // find an edge
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			vector<int> ask1 = cur;
			for (int i = 0; i < mid; i++)
				ask1.push_back(rem[i]);
			vector<int> ask2;
			for (int i = 0; i < mid; i++)
				ask2.push_back(rem[i]);
			if (query(ask1) - query(ask2) == curedge)
				l = mid;
			else
				r = mid;
		}
		int u = rem[l];
		vector<int> odd, even;
		for (auto u : cur) if (col[u] == 0) {
				odd.push_back(u);
			} else {
				even.push_back(u);
			}
		bool podd = existEdge(u, odd);
		bool peven = existEdge(u, even);

		if (podd && peven) {
			int p1 = findEdge(u, odd);
			int p2 = findEdge(u, even);
			assert(p1 != -1 && p2 != -1);
			addEdge(u, p1);
			addEdge(u, p2);
			findCycle(u);
		}

		assert(podd || peven);
		if (podd) {
			int v = findEdge(u, odd);
			addEdge(u, v);
			col[u] = 1;
		}

		if (peven) {
			int v = findEdge(u, even);
			addEdge(u, v);
			col[u] = 0;
		}
		vis[u] = 1;
		cur.push_back(u);
		curedge = query(cur);
	}
	vector<int> part;
	for (int i = 1; i <= n; i++) if (col[i] == 0) {
			part.push_back(i);
		}
	printf("Y %d\n", (int)part.size());
	for (auto u : part) printf("%d ", u);
	puts("");
}