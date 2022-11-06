#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n;
int a[maxn];
vector<int> graph[maxn];
int ans[maxn];

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

void dfs1(int v, int p) {
    if (p != -1) {
        ans[v] = gcd(a[v], ans[p]);
    }
    for (auto to: graph[v]) {
        if (to != p) {
            dfs1(to, v);
        }
    }
}

void dfs2(int v, int div, int cnt, int p) {
    if (a[v] % div != 0) {
        ++cnt;
    }
    if (cnt <= 1) {
        ans[v] = max(ans[v], div);
    } else {
        return;
    }
    for (auto to: graph[v]) {
        if (to != p) {
            dfs2(to, div, cnt, v);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs1(1, -1);
    vector<int> divs;
    for (int i = 1; i <= a[1]; ++i) {
        if (a[1] % i == 0) {
            divs.push_back(i);
        }
    }
    for (auto i: divs) {
        dfs2(1, i, 0, -1);
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
}