#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    if (m < n - 1) {
        cout << "Impossible" << '\n';
        return 0;
    }

    vector<pair<int, int>> graph;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n && m > (int)graph.size(); j++) {
            if (gcd(i, j) == 1)
                graph.emplace_back(i, j);
        }
    }

    if (m == (int)graph.size()) {
        cout << "Possible" << '\n';
        for (auto [x, y] : graph)
            cout << x << " " << y << '\n';
    } else {
        cout << "Impossible" << '\n';
    }
}