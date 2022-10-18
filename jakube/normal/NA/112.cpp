#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    int mask = (1 << n) - 1;
    vector<int> adj((1 << n) + m, -1);
    int offset = 1 << n;
    for (int i = 0; i < m; i++) {
        adj[mask ^ v[i]] = offset + i;
    }

    int cnt = 0;
    vector<int> visited(adj.size(), false);
    for (int i = 0; i < m; i++) {
        if (visited[offset + i])
            continue;
        cnt++;
        queue<int> q;
        q.push(offset + i);
        visited[offset + i] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (x >= offset && !visited[v[x - offset]]) {
                int y = v[x - offset];
                visited[y] = true;
                q.push(y);
            }
            if (x < offset) {
                for (int j = 0; j < n; j++) {
                    if (x < (x | (1 << j))) {
                        int y = x | (1 << j);
                        if (!visited[y]) {
                            visited[y] = true;
                            q.push(y);
                        }
                    }
                }
                if (adj[x] >= 0) {
                    int y = adj[x];
                    if (!visited[y]) {
                        visited[y] = true;
                        q.push(y);
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
}