#include <bits/stdc++.h>

using namespace std;

const int maxn = 30005;

struct Edge {
    int to;
    int number;
};

vector<Edge> graph[maxn];
int cost[maxn];
char used[maxn];

vector<int> path;

bool dfs1(int v, int fin) {
    if (v == fin) return true;
    used[v] = true;
    for (auto e: graph[v]) {
        if (!used[e.to]) {
            path.push_back(e.number);
            if (dfs1(e.to, fin)) return true;
            path.pop_back();
        }
    }
    return false;
}

int deleted;
bool dfs2(int v, int fin) {
    if (v == fin) return true;
    used[v] = true;
    for (auto e: graph[v]) {
        if (!used[e.to] && e.number != deleted) {
            if (dfs2(e.to, fin)) return true;
        }
    }
    return false;
}

int timer, tin[maxn], fup[maxn];
vector<int> bridges;

bool dfs(int v, int fin, int p) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	bool flag = (v == fin);
	for (auto e: graph[v]) {
		if (e.number == p || e.number == deleted)  continue;
		if (used[e.to])
			fup[v] = min(fup[v], tin[e.to]);
		else {
			bool flag2 = dfs(e.to, fin, e.number);
			flag |= flag2;
			fup[v] = min(fup[v], fup[e.to]);
			if (flag2 && fup[e.to] > tin[v])
				bridges.push_back(e.number);
		}
	}
	return flag;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    int st, fin;
    cin >> st >> fin;
    st--; fin--;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        graph[x].push_back(Edge{y, i});
        graph[y].push_back(Edge{x, i});
        cost[i] = w;
    }

    if (!dfs1(st, fin)) {
        cout << 0 << endl;
        cout << 0 << endl;
        return 0;
    }

    int ans = 2e9 + 1;
    vector<int> vans;

    for (auto e: path) {
        deleted = e;
        memset(used, false, n);
        if (!dfs2(st, fin)) {
            if (cost[e] < ans) {
                ans = cost[e];
                vans = {e + 1};
            }
            continue;
        }
        memset(used, false, n);
        timer = 0;
        bridges.clear();
        dfs(st, fin, -1);
        for (auto x: bridges) {
            if (cost[e] + cost[x] < ans) {
                ans = cost[e] + cost[x];
                vans = {e + 1, x + 1};
            }
        }
    }

    if (ans > (int) 2e9) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
    cout << vans.size() << endl;
    for (auto i: vans) {
        cout << i << ' ';
    }
}