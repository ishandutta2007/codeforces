#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, m, q;
vector<int> edge[100001];
int dep[1000001];
int ps[100001];
int back[100001];

vector<int> tree[1000001];

void dfs(int x, int p) {
    ps[x] = p;
    dep[x] = dep[p] + 1;
    back[x] = dep[x];
    int bot = 1;
    for (int i : edge[x]) {
        if (i == p) continue;
        if (dep[i]) {
            back[x] = min(back[x], dep[i]);
        }
        else {
            dfs(i, x);
            if (back[i] < dep[x]) bot = 0;
            back[x] = min(back[x], back[i]);
        }
    }
    if (bot) {
        if (back[x] < dep[x]) {
            int np = ++n;
            for (int i = x; back[x] <= dep[i]; i = ps[i]) {
                tree[i].push_back(np);
                tree[np].push_back(i);
            }
        }
        else if (p) {
            int np = ++n;
            tree[x].push_back(np);
            tree[np].push_back(x);
            tree[p].push_back(np);
            tree[np].push_back(p);
        }
    }
}

int par[1000001][20];
void dfs2(int x, int p) {
    dep[x] = dep[p] + 1;
    par[x][0] = p;
    for (int i = 1; i < 20; ++i) {
        par[x][i] = par[par[x][i - 1]][i - 1];
    }
    for (int i : tree[x]) {
        if (i == p) continue;
        dfs2(i, x);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 20; i--; ) {
        if ((dep[x] - dep[y]) >> i) x = par[x][i];
    }
    if (x == y) return x;
    for (int i = 20; i--; ) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
	}
	dfs(1, 0);
	dfs2(1, 0);
	for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        int p = lca(x, y);
        printf("%d\n", dep[x] + dep[y] - 2 * dep[p] >> 1);
	}
	return 0;
}