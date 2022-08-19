#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1E5;
int n;
int parent[MAX_N];
vector<int> e[MAX_N];
int cnt;
int a[MAX_N];
int p[MAX_N], dep[MAX_N], h[MAX_N];
vector<int> ans;
void dfs1(int u) {
    h[u] = dep[u];
    for (int v : e[u]) {
        dep[v] = dep[u] + 1;
        dfs1(v);
        h[u] = max(h[u], h[v]);
    }
}
void dfs2(int u) {
    a[cnt++] = u;
    sort(e[u].begin(), e[u].end(), [&](int i, int j) {return h[i] < h[j];});
    for (int v : e[u])
        dfs2(v);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    parent[0] = -1;
    for (int i = 1; i < n; ++i) {
        cin >> parent[i];
        e[parent[i]].push_back(i);
    }
    dfs1(0);
    dfs2(0);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " \n"[i == n - 1];
    p[0] = -1;
    for (int i = 1; i < n; ++i)
        p[a[i]] = a[i - 1];
    for (int i = 1; i < n; ++i) {
        int u = a[i];
        while (p[u] != parent[u]) {
            ans.push_back(u);
            p[u] = p[p[u]];
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i == ans.size() - 1];
    return 0;
}