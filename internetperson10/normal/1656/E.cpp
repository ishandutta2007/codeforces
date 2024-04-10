#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        vector<pair<int, int>> v(n-1);
        vector<int> bic(n);
        for(int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bic[0] = 1;
        function<void(int)> dfs;
        dfs = [&](int n) {
            for(int ch : adj[n]) {
                if(bic[ch]) continue;
                bic[ch] = -bic[n];
                dfs(ch);
            }
        };
        dfs(0);
        for(int i = 0; i < n; i++) {
            cout << bic[i] * (int)adj[i].size() << ' ';
        }
        cout << '\n';
    }
}