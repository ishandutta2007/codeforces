#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;
    cin >> n >> k >> m;
    vector<vector<int>> groups(m);

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        groups[v[i] % m].push_back(v[i]);
    }

    for (auto &g : groups) {
        if (g.size() >= k) {
            cout << "Yes" << endl;
            for (int i = 0; i < k; i++) {
                cout << g[i] << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}