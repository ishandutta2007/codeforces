#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int n, m;
int A[1000001];
int B[1000001];
int E[1000001];
bool C[1000001];

int uf[100001];

int find(int x) {
    if (uf[x]) return uf[x] = find(uf[x]);
    return x;
}

vector<pii> edge[100001];
int dep[100001];
int par[100001][17];
int dis[100001][17];
void dfs(int x, int p) {
    for (int i = 1; i < 17; ++i) {
        par[x][i] = par[par[x][i - 1]][i - 1];
        dis[x][i] = max(dis[x][i - 1], dis[par[x][i - 1]][i - 1]);
    }
    for (pii i : edge[x]) {
        if (i.first == p) continue;
        dep[i.first] = dep[x] + 1;
        par[i.first][0] = x;
        dis[i.first][0] = i.second;
        dfs(i.first, x);
    }
}

int get_max(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    int ret = 0;
    for (int i = 17; i--; ) if (dep[x] - dep[y] >> i) {
        ret = max(ret, dis[x][i]);
        x = par[x][i];
    }
    if (x == y) return ret;
    for (int i = 17; i--; ) if (par[x][i] != par[y][i]) {
        ret = max(ret, max(dis[x][i], dis[y][i]));
        x = par[x][i];
        y = par[y][i];
    }
    return max(ret, max(dis[x][0], dis[y][0]));
}

int col[100001][17];

void paint(int x, int l, int v) {
    if (col[x][l] != -1) return;
    col[x][l] = v;
    if (l == 0) return;
    paint(x, l - 1, v);
    paint(par[x][l - 1], l - 1, v); 
}

void coloring(int x, int y, int v) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 17; i--; ) if (dep[x] - dep[y] >> i) {
        paint(x, i, v);
        x = par[x][i];
    }
    if (x == y) return;
    for (int i = 17; i--; ) if (par[x][i] != par[y][i]) {
        paint(x, i, v);
        paint(y, i, v);
        x = par[x][i];
        y = par[y][i];
    }
    paint(x, 0, v);
    paint(y, 0, v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<int> ord;
    for (int i = 1; i <= m; ++i) {
        cin >> A[i] >> B[i] >> E[i];
        ord.push_back(i);
    }
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        return E[a] < E[b];
    });
    for (int i : ord) {
        int x = find(A[i]), y = find(B[i]);
        if (x != y) {
            C[i] = 1;
            uf[y] = x;
            edge[A[i]].emplace_back(B[i], E[i]);
            edge[B[i]].emplace_back(A[i], E[i]);
        }
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) for (int j = 0; j < 17; ++j) {
        col[i][j] = -1;
    }
    for (int i : ord) {
        if (C[i]) continue;
        coloring(A[i], B[i], E[i]);
    }
    for (int i = 1; i <= m; ++i) {
        if (C[i]) {
            int x;
            if (dep[A[i]] < dep[B[i]]) x = B[i];
            else x = A[i];
            int v = col[x][0];
            if (v == -1) v = 1e9;
            printf("%d\n", v);
        }
        else {
            printf("%d\n", get_max(A[i], B[i]));
        }
    }
    return 0;
}