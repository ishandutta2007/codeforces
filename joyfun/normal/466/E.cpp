#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MP(a,b) make_pair(a,b)
typedef pair<int, int> pii;
const int N = 100005;

int n, m, parent[N];

int find(int x) {
    return x == parent[x] ? x : parent[x]  = find(parent[x]);
}

vector<pii> p, q[N];
vector<int> g[N];
int tot, vis[N], cnt[N];

void dfs(int u) {
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++)
        dfs(g[u][i]);
    for (int i = 0; i < q[u].size(); i++) {
        if (vis[q[u][i].first])
            cnt[q[u][i].second]++;
    }
    vis[u] = 0;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    int c, x, y;
    while (m--) {
        scanf("%d%d", &c, &x);
        if (c == 2)
            p.push_back(MP(find(x), x));
        else {
            scanf("%d", &y);
            if (c == 1) {
                g[y].push_back(x);
                int px = find(x);
                int py = find(y);
                if (px != py)
                    parent[px] = py;
            } else {
                q[x].push_back(MP(p[y - 1].first, tot));
                q[p[y - 1].second].push_back(MP(x, tot));
                tot++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (parent[i] == i) dfs(i);
    for (int i = 0; i < tot; i++)
        if (cnt[i] == 2) printf("YES\n");
        else printf("NO\n");
    return 0;
}