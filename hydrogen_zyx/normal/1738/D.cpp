#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6 + 10;

int b[N];

vector<int> g[N];
vector<int> v;
int siz[N];

void dfs(int u) {
    siz[u] = 1;
    for (auto x: g[u]) {
        dfs(x);
        siz[u] += siz[x];
    }
}

void dfs2(int u) {
    if (u) v.push_back(u);
    for (auto x: g[u]) {
        if (siz[x] != 1) continue;
        dfs2(x);
    }
    for (auto x: g[u]) {
        if (siz[x] == 1) continue;
        dfs2(x);
    }

}

int lmin[N], rmax[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++) g[i].clear();
        for (int i = 1; i <= n; i++) cin >> b[i];
        lmin[0] = 0x3f3f3f3f;
        rmax[n + 1] = 0;
        for (int i = 1; i <= n; i++) lmin[i] = min(lmin[i - 1], b[i]);
        for (int i = n; i >= 1; i--) rmax[i] = max(rmax[i + 1], b[i]);
        int k = 0;
        for (int i = 0; i <= n; i++) {
            if (lmin[i] > i && rmax[i + 1] < i + 1) k = i;
        }
        for (int i = 1; i <= n; i++) {
            if (b[i] == 0 || b[i] == n + 1) {
                g[0].push_back(i);
            } else {
                g[b[i]].push_back(i);
            }
        }
        v.clear();
        dfs(0);
        dfs2(0);
        cout << k << endl;
        for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
        cout << endl;
    }
}