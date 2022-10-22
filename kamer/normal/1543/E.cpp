#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int N = (1 << n);
        vector<vector<int>> graph(N, vector<int>());
        vector<vector<int>> parents(N, vector<int>());
        vector<int> dist(N, -1);
        
        for (int i = 0; i < n * N / 2; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> perm(N, -1);
        vector<int> inv_perm(N, 0);
        queue<tuple<int, int>> dijk;

        inv_perm[0] = 0;
        dist[0] = 0;
        int count = 0;
        for (auto u : graph[0]) {
            dist[u] = 1;
            inv_perm[u] = (1 << count);
            dijk.push({ u, 1 });
            count++;
        }

        while (!dijk.empty()) {
            auto [v, d] = dijk.front();
            dijk.pop();

            for (auto u : graph[v]) {
                if (dist[u] == -1) {
                    dist[u] = d + 1;
                    dijk.push({ u, d + 1 });
                }

                if (dist[u] == d + 1) {
                    inv_perm[u] |= inv_perm[v];
                }
            }
        }

        for (int i = 0; i < N; i++) {
            perm[inv_perm[i]] = i;
        }

        for (auto v : perm) cout << v << " ";
        cout << endl;

        int log = -1;
        int n_copy = n;
        while (n_copy > 0) {
            n_copy /= 2;
            log++;
        }

        if (n != (1 << log)) {
            cout << "-1\n";
            continue;
        }

        vector<int> color(N, 0);
        for (int i = 0; i < N; i++) {
            int j = i;
            int k = 0;
            while (j != 0) {
                if (j % 2 == 1) color[i] ^= k;
                j /= 2;
                k++;
            }
        }

        vector<int> act_color(N, -1);
        for (int i = 0; i < N; i++) {
            act_color[perm[i]] = color[i];
        }

        for (auto c : act_color) cout << c << " ";
        cout << "\n";
    }

}