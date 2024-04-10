#include <bits/stdc++.h>
using namespace std;

vector<int> size, order, first;
vector<vector<int>> children;

int t = 0;

int dfs(int v) {
    ::size[v] = 1;
    first[v] = t;
    order[t++] = v;
    for (int u : children[v]){
        ::size[v] += dfs(u);
    }
    return ::size[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    children.resize(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        children[x-1].push_back(i);
    }

    ::size.resize(n);
    order.resize(n);
    first.resize(n);
    dfs(0);

    for (int i = 0; i < q; i++) {
        int u, k;
        cin >> u >> k;
        u--;
        if (::size[u] < k) {
            cout << -1 << '\n';
        } else {
            cout << order[first[u] + k - 1] + 1 << '\n';
        }
    }
}