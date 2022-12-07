#include <bits/stdc++.h>
using namespace std;

const int MAXNODE = 100005 * 2; //

struct TwoSat {
	int n;
	vector<int> g[MAXNODE];
	int pre[MAXNODE], dfn[MAXNODE], dfs_clock, sccn, sccno[MAXNODE];
	stack<int> S;
	int mark[MAXNODE];

	void init(int tot) {
		n = tot * 2;
		for (int i = 0; i < n; i+= 2) {
			g[i].clear();
			g[i^1].clear();
		}
	}

	void add_Edge(int u, int uval, int v, int vval) {
		u = u * 2 + uval;
		v = v * 2 + vval;
		g[u^1].push_back(v);
		g[v^1].push_back(u);
	}

	void dfs_scc(int u) {
        pre[u] = dfn[u] = ++dfs_clock;
        S.push(u);
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (!pre[v]) {
                dfs_scc(v);
                dfn[u] = min(dfn[u], dfn[v]);
            } else if (!sccno[v]) dfn[u] = min(dfn[u], pre[v]);
        }
        if (pre[u] == dfn[u]) {
            sccn++;
            while (1) {
                int x = S.top(); S.pop();
                sccno[x] = sccn;
                if (x == u) break;
            }
        }
	}

	void find_scc() {
        dfs_clock = sccn = 0;
        memset(sccno, 0, sizeof(sccno));
        memset(pre, 0, sizeof(pre));
        for (int i = 0; i < n; i++)
            if (!pre[i]) dfs_scc(i);
	}

	bool solve() {
	    find_scc();
        for (int i = 0; i < n; i += 2) {
            if (sccno[i] == sccno[i + 1]) return false;
            mark[i / 2] = (sccno[i] > sccno[i + 1]);
        }
        return true;
	}
} gao;

const int N = 100005;
int n, m, a[N];
vector<int> g[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    gao.init(m);
    for (int i = 0; i < m; i++) {
        int k, x;
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &x);
            g[x].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        int u = g[i][0];
        int v = g[i][1];
        if (a[i]) {
            gao.add_Edge(u, 1, v, 0);
            gao.add_Edge(u, 0, v, 1);
        } else {
            gao.add_Edge(u, 1, v, 1);
            gao.add_Edge(u, 0, v, 0);
        }
    }
    printf("%s\n", gao.solve() ? "YES" : "NO");
    return 0;
}