#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 10;

int root = 0;
int deep[N];
int par[N][20];

vector<int> g[N];

bool hasBit(int mask, int i) { return (mask & (1 << i)); }

int goUp(int v, int len) {
    for (int i = 19; i >= 0; --i)
        if (hasBit(len, i)) v = par[v][i];
    return v;
}

int getLCA(int v, int u) {
    if (deep[v] < deep[u]) swap(v, u);
    v = goUp(v, deep[v] - deep[u]);
    for (int i = 19; i >= 0; --i) {
        if (par[v][i] != par[u][i]) {
            v = par[v][i];
            u = par[u][i];
        }
    }
    if (v != u) return par[v][0];
    return v;
}

pair<int, int> getToRoot(int v) {
    int dv = deep[v];
    int dr = deep[root];
    int w = getLCA(v, root);
    int dw = deep[w];
    int ans = (dv - dw + dr - dw);

    if (dv < dr || w != root) {
        int ansv = par[root][0];
        return make_pair(ans, ansv);
    }

    int ansv = goUp(v, deep[v] - deep[root] - 1);
    return make_pair(ans, ansv);
}

int halfdiam = 0;
bool eq = true;
int lastv = 1;

void addV(int p) {
    int v = lastv++;
    deep[v] = deep[p] + 1;
    g[p].push_back(v);
    for (int i = 0; i < 20; ++i) {
        par[v][i] = p;
        p = par[p][i];
    }
    pair<int, int> pa = getToRoot(v);
    int dist = pa.first;
    int near = pa.second;
    if (dist <= halfdiam) return;
    if (dist > halfdiam) {
        if (deep[near] > deep[root]) {
            if (!eq) {
                halfdiam++;
                eq = true;
            } else {
                eq = false;
                root = near;
            }
        } else {
            if (dist == halfdiam + 1) {
                eq = false;
            } else {
                eq = true;
                halfdiam++;
                root = near;
            }
        }
    }
}

int main() {
    for (int i = 1; i <= 3; ++i) addV(0);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int v;
        scanf("%d", &v);
        --v;
        addV(v);
        addV(v);
        int ans = halfdiam * 2;
        if (!eq) ans++;
        printf("%d\n", ans);
    }

    return 0;
}