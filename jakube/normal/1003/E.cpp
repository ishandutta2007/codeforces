#include <bits/stdc++.h>
using namespace std;

int n, last, k;
vector<pair<int, int>> edges;
vector<int> degree;

void dfs(int v, int togo) {
    if (togo == 0)
        return;

    while (degree[v] < k && last < n - 1) {
        last++;
        edges.push_back({v, last});
        degree[v]++;
        degree[last]++;
        dfs(last, togo - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d;
    cin >> n >> d >> k;
    
    // 0..1..2....d = diameter
    if (n <= d || (k == 1 && n > 2)) {
        cout << "NO" << '\n';
        return 0;
    }

    degree.assign(n, 0);
    for (int i = 0; i < d; i++) {
        edges.push_back({i, i+1});
        degree[i]++;
        degree[i+1]++;
    }
    last = d;
    
    for (int i = 0; i <= d; i++) {
        dfs(i, min(i, d - i));
    }

    if (last == n - 1) {
        cout << "YES" << '\n';
        for (auto [u, v] : edges)
            cout << u + 1 << " " << v + 1 << '\n';
    } else
        cout << "NO" << '\n';
}