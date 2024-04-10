#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> w(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        vector<vector<int>> g(n);
        for (int i = 0; i + 1 < n; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&] (int x, int y) { return w[x] > w[y]; });
        long long ans = accumulate(w.begin(), w.end(), 0ll);
        cout << ans << " ";
        for (auto v : id) {
            for (int j = 0; j + 1 < (int) g[v].size(); j++) {
                ans += w[v];
                cout << ans << " ";
            }
        }
        cout << '\n';
    }
}