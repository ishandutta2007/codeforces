#include <bits/stdc++.h>
using namespace std;
const int N = 8e4 + 1;

struct edge {
    int a, b, f, c;
};

edge w[4*N];
int p[N], h[N], ans[N], MXM, top = 0;
vector <int> e[2*N], an[N];
bool used[2*N];

void create_edge(int a, int b, int c) {
    ++top;
    w[top].a = a;
    w[top].b = b;
    w[top].c = c;
    p[top] = MXM + top;
    p[MXM + top] = top;
    w[top + MXM].a = b;
    w[top + MXM].b = a;
    e[a].push_back(top);
    e[b].push_back(MXM + top);
}

bool bfs(int ist, int st, int n) {
    int s[N], h1 = 1, top = 1;
    for (int i = 0; i <= n; ++i)
        used[i] = false;
    s[1] = ist;
    used[ist] = true;
    h[ist] = 0;
    while (h1 <= top) {
        for (int i = 0; i < e[s[h1]].size(); ++i)
        if (w[e[s[h1]][i]].f < w[e[s[h1]][i]].c && !used[w[e[s[h1]][i]].b]) {
            used[w[e[s[h1]][i]].b] = true;
            h[w[e[s[h1]][i]].b] = h[s[h1]] + 1;
            ++top;
            s[top] = w[e[s[h1]][i]].b;
        }
        ++h1;
    }
    return used[st];
}

bool dfs(int u, int st) {
    if (u == st)
        return true;
    used[u] = true;
    for (int i = 0; i < e[u].size(); ++i)
    if (!used[w[e[u][i]].b] && h[w[e[u][i]].b] == h[u] + 1 && w[e[u][i]].f < w[e[u][i]].c && dfs(w[e[u][i]].b, st)) {
        ++w[e[u][i]].f;
        --w[p[e[u][i]]].f;
        return true;
    }
    return false;
}


int dinic(int ist, int st, int n) {
    while (true) {
        if (!bfs(ist, st, n))
            break;
        for (int i = 0;  i <= n; ++i)
            used[i] = false;
        while (dfs(ist, st)) {
            for (int i = 0;  i <= n; ++i)
                used[i] = false;
        }
    }
    int flow = 0;
    for (int i = 1; i <= MXM; ++i)
    if (w[i].b == st)
        flow += w[i].f;
    return flow;
}


int main() {
    int i, j, n1, n2, m, a, b;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n1 >> n2 >> m;
    MXM = n1 + n2 + m;
    int ist = 0, st = n1 + n2 + 1;
    for (i = 0; i < m; ++i) {
        cin >> a >> b;
        create_edge(a, b + n1, 1);
    }
    int mindeg = m;
    for (i = 1; i <= n1 + n2; ++i)
        mindeg = min(mindeg, (int)e[i].size());
    for (i = 1; i <= n1; ++i)
        create_edge(ist, i, e[i].size() - mindeg);
    for (i = 1; i <= n2; ++i)
        create_edge(i + n1, st, e[i + n1].size() - mindeg);
    for (i = 0; i <= mindeg; ++i) {
        ans[i] = m - dinic(ist, st, n1 + n2 + 1);
        for (j = 1; j <= m; ++j)
        if (w[j].f == 0)
            an[i].push_back(j);
        for (j = m + 1; j <= n1 + n2 + m; ++j)
            ++w[j].c;
    }
    for (i = mindeg; i >= 0; --i) {
        cout << ans[i];
        for (j = 0; j < an[i].size(); ++j)
            cout << ' ' << an[i][j];
        cout << "\n";
    }
}