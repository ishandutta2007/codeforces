#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    if (n % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    if (n == 1) {
        cout << "2 1\n1 2\n";
        return 0;
    }

    vector<pair<int, int>> edges;

    edges.push_back({1, n+3});
    for (int j = 0; j < n-1; j++) {
        edges.push_back({1, 2+j});
        edges.push_back({n+3, n+4+j});
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n-1; j++) {
            if (i % 2 == 0 && j == i+1) continue;
            edges.push_back({2+i, 2+j});
            edges.push_back({n+4+i, n+4+j});
        }
        edges.push_back({n+2, i+2});
        edges.push_back({n+1, i+2});
        edges.push_back({2*n+3, n+4+i});
        edges.push_back({2*n+4, n+4+i});
    }
    edges.push_back({n+1, n+2});
    edges.push_back({2*n+4, 2*n+3});

    cout << 2*n+4 << " " << edges.size() << endl;
    for (auto p : edges) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}