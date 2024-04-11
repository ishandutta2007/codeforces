#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n;
vector<int> graph[maxn];
int c[maxn];
int cnt[maxn];
char good[maxn];
int size[maxn];

void out(int v) {
    cout << "YES\n";
    cout << v + 1 << '\n';
    exit(0);
}

void dfs1(int v, int p=-1) {
    size[v] = 1;
    for (auto u: graph[v]) {
        if (u != p) {
            dfs1(u, v);
            size[v] += size[u];
        }
    }
}

void dfs(int v, int p=-1) {
    for (auto u: graph[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    good[v] = true;
    bool flag = true;
    for (auto u: graph[v]) {
        if (u != p) {
            good[v] &= good[u];
            flag &= good[u];
            good[v] &= (c[u] == c[v]);
        }
    }
    if (!flag) return;
    if (p == -1) out(v);
    for (auto u: graph[v]) {
        if (u != p) {
            cnt[c[u]] -= size[u];
        }
    }
    --cnt[c[v]];
    if (cnt[c[p]] == n - size[v]) out(v);
    ++cnt[c[v]];
    for (auto u: graph[v]) {
        if (u != p) {
            cnt[c[u]] += size[u];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        ++cnt[c[i]];
    }

    dfs1(0);
    dfs(0);
    cout << "NO\n";
}