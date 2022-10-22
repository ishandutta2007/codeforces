#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e3;
vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
int a[N][N], dist[N][N], res[2];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, w;
    cin >> n >> m >> w;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> kek = {{0, 0}, {n - 1, m - 1}};
    int ans = 1e18;
    for (int t = 0; t < 2; t++) {
        queue<pair<int, int>> st; st.push({kek[t].first, kek[t].second});
        for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, 1e18);
        dist[kek[t].first][kek[t].second] = 0;
        int tmp = 1e18;
        while ((int) st.size() > 0) {
            int x, y;
            tie(x, y) = st.front();
            st.pop();
            if (a[x][y] > 0) tmp = min(tmp, dist[x][y] + a[x][y]);
            for (int j = 0; j < 4; j++) {
                    int x2 = dx[j] + x, y2 = dy[j] + y;
                    if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && a[x2][y2] != -1) {
                        if (dist[x2][y2] > dist[x][y] + w) {
                            dist[x2][y2] = dist[x][y] + w;
                            st.push({x2, y2});
                        }
                    }
                }
        }
        res[t] = tmp;
        if (!t) ans = min(ans, dist[n - 1][m - 1]);
    }
    ans = min(ans, res[0] + res[1]);
    if (ans == (int) 1e18) {
        cout << -1;
    }
    else {
        cout << ans;
    }
}