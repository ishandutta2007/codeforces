#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;
const int INF = 0x3f3f3f3f;

int n, lm, rm;
int q[N], fa[N], sz[N];
bool use[N];
vector<pair<int, int> > g[N];

int getc(int u) {
    int qn = 0; fa[q[qn++] = u] = u;
    for (int i = 0; i < qn; i++) {
        u = q[i]; sz[u] = 1;
        for (int j = 0; j < g[u].size(); j++) {
            int v = g[u][j].first;
            if (use[v] || v == fa[u]) continue;
            fa[q[qn++] = v] = u;
        }
    }
    for (int i = qn - 1; i >= 0; i--) {
        int u = q[i];
        if (sz[u] * 2 > qn) return u;
        sz[fa[u]] += sz[u];
    }
}

int dep[N];

void dfs(int u, int p) {
    dep[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first;
        if (v == p || use[v]) continue;
        dfs(v, u);
        dep[u] = max(dep[u], dep[v] + 1);
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return dep[a.first] < dep[b.first];
}

int Maxc;

pair<int, int> f[N], ff[N];
int Q[N];

void dfs(int u, int p, int d, int val, int mid) {
    f[d] = max(f[d], make_pair(val, u));
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first;
        int w = g[u][i].second;
        if (v == p || use[v]) continue;
        dfs(v, u, d + 1, val + (w >= mid ? 1 : -1), mid);
    }
}

pair<int, int> tmp;

bool judge(int u, int mid) {
    int pre = 0;
    for (int i = 0; i <= dep[u]; i++) ff[i] = make_pair(-INF, 0);
    ff[0] = make_pair(0, u);
    int ed = 0;
    for (int ii = 0; ii < g[u].size(); ii++) {
        int v = g[u][ii].first;
        int w = g[u][ii].second;
        if (use[v]) continue;
        for (int i = 0; i <= dep[v]; i++) f[i] = make_pair(-INF, 0);
        dfs(v, u, 1, w >= mid ? 1 : -1, mid);
        int head = 0, rear = 0;
        for (int i = 0; i <= dep[v]; i++) {
            while (ed >= 0 && i + ed >= lm) {
                while (head < rear && ff[Q[rear - 1]] < ff[ed]) rear--;
                Q[rear++] = ed--;
            }
            while (head < rear && Q[head] + i > rm) head++;
            if (head < rear && ff[Q[head]].first + f[i].first >= 0) {
                tmp = make_pair(ff[Q[head]].second, f[i].second);
                return true;
            }
        }
        for (int i = 0; i <= dep[v]; i++) ff[i] = max(f[i], ff[i]);
        ed = dep[v];
    }
    return false;
}

int ans = -1;
pair<int, int> an;

void cal(int u) {
    dfs(u, u);
    sort(g[u].begin(), g[u].end(), cmp);
    int l = ans, r = Maxc;
    if (!judge(u, l)) return;
    while (l < r) {
        int mid = (l + r)>>1;
        if (judge(u, mid)) l = mid + 1;
        else r = mid;
    }
    judge(u, l - 1);
    if (ans < l - 1) {
        ans = l - 1;
        an = tmp;
    }
}

void go(int c) {
    int rt = getc(c);
    use[rt] = true;
    cal(rt);
    for (int i = 0; i < g[rt].size(); i++) {
        int v = g[rt][i].first;
        if (use[v]) continue;
        go(v);
    }
}

int main() {
    scanf("%d%d%d", &n, &lm, &rm);
    int u, v, w;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d%d", &u, &v, &w);
        Maxc = max(Maxc, w + 1);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    go(1);
    printf("%d %d\n", an.first, an.second);
    return 0;
}