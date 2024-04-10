#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> x(n), y(n), k(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    vector<LL> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i)
        cin >> k[i];
    vector<bool> visited(n);
    vector<int> parent(n, -1);
    LL total = 0;
    vector<int> sta;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j)
            if (!visited[j] && (u == -1 || c[j] < c[u]))
                u = j;
        visited[u] = true;
        total += c[u];
        if (parent[u] == -1)
            sta.push_back(u);
        for (int j = 0; j < n; ++j) {
            if (!visited[j]) {
                LL cost = 1LL * (k[u] + k[j]) * (abs(x[u] - x[j]) + abs(y[u] - y[j]));
                if (cost < c[j]) {
                    c[j] = cost;
                    parent[j] = u;
                }
            }
        }    
    }
    cout << total << "\n";
    cout << sta.size() << "\n";
    for (int i : sta)
        cout << i + 1 << "\n";
    cout << n - sta.size() << "\n";
    for (int i = 0; i < n; ++i)
        if (parent[i] != -1)
            cout << i + 1 << " " << parent[i] + 1 << "\n";
    return 0;
}