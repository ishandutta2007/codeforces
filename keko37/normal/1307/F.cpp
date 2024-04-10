#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 400005;
const int LOG = 19;

int n, k, r, cnt, qq;
int rest[MAXN], dist[MAXN], col[MAXN], dub[MAXN];
int par[LOG][MAXN];
vector <int> v[MAXN];
queue <int> q;

int nadi (int x) {
    if (x == col[x]) return x;
    return col[x] = nadi(col[x]);
}

void spoji (int x, int y) {
    col[nadi(x)] = nadi(y);
}

void bfs () {
    memset(dist, -1, sizeof dist);
    for (int i = 1; i <= n; i++) col[i] = i;
    for (int i = 1; i <= r; i++) {
        q.push(rest[i]);
        dist[rest[i]] = 0;
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (dist[x] == k) continue;
        for (auto sus : v[x]) {
            spoji(x, sus);
            if (dist[sus] == -1) {
                dist[sus] = dist[x] + 1;
                q.push(sus);
            }
        }
    }
}

void dfs (int x, int rod) {
    dub[x] = 1 + dub[rod];
    par[0][x] = rod;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        dfs(sus, x);
    }
}

void precompute () {
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}

int kth (int x, int k) {
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) x = par[i][x];
    }
    return x;
}

int lca (int x, int y) {
    if (dub[x] < dub[y]) swap(x, y);
    x = kth(x, dub[x] - dub[y]);
    if (x == y) return x;
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[i][x] != par[i][y]) {
            x = par[i][x];
            y = par[i][y];
        }
    }
    return par[0][x];
}

int mv (int x, int y, int g, int len) {
    if (y == g) return kth(x, len);
    if (x == g) return kth(y, dub[y] - dub[x] - len);
    if (len <= dub[x] - dub[g]) return kth(x, len);
    return mv(g, y, g, len - dub[x] + dub[g]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> r;
    for (int i = n - 2; i >= 0; i--) {
        int a, b;
        cin >> a >> b;
        n++;
        v[a].push_back(n); v[n].push_back(a);
        v[b].push_back(n); v[n].push_back(b);
    }
    for (int i = 1; i <= r; i++) {
        cin >> rest[i];
    }
    bfs();
    dfs(1, 0);
    precompute();
    cin >> qq;
    for (int i = 0; i < qq; i++) {
        int a, b, g;
        cin >> a >> b;
        g = lca(a, b);
        if (dub[a] + dub[b] - 2 * dub[g] <= 2 * k) {
            cout << "YES\n";
        } else {
            int na = mv(a, b, g, k);
            int nb = mv(b, a, g, k);
            if (nadi(na) == nadi(nb)) cout << "YES\n"; else cout << "NO\n";
        }
    }
    return 0;
}