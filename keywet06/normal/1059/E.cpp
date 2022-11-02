#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = int(1e5) + 5;

int n, L, ans = 0;
int c[N], ol[N];

int64 S;
int64 ov[N];

multiset<pair<int, int64> > s[N];
vector<int> G[N];

void dfs(int u) {
    for (auto v : G[u]) {
        dfs(v);
        if (s[v].size() > s[u].size()) {
            s[u].swap(s[v]);
            swap(ol[u], ol[v]);
            swap(ov[u], ov[v]);
        }
    }
    ++ol[u], ov[u] += c[u];
    for (auto v : G[u]) {
        for (auto vv : s[v]) {
            s[u].insert({vv.first + ol[v] + 1 - ol[u],
                         vv.second + ov[v] + c[u] - ov[u]});
        }
    }
    while (s[u].size() && (*s[u].rbegin()).first + ol[u] > L) {
        s[u].erase(s[u].find(*s[u].rbegin())), ++ans;
    }
    while (s[u].size() && (*s[u].rbegin()).second + ov[u] > S) {
        s[u].erase(s[u].find(*s[u].rbegin())), ++ans;
    }
    if (s[u].empty()) s[u].insert({1 - ol[u], c[u] - ov[u]});
}

int main() {
    scanf("%d", &n);
    scanf("%d %lld", &L, &S);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        if (c[i] > S) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        G[x].push_back(i);
    }
    dfs(1);
    printf("%d", ans + (int)s[1].size());
    return 0;
}