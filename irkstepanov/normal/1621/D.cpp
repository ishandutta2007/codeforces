#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        int k = 2 * n;
        vector<vector<ll> > c(k, vector<ll>(k));
        ll ans = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                cin >> c[i][j];
                if (i >= n && j >= n) {
                    ans += c[i][j];
                    c[i][j] = 0;
                }
            }
        }
        cout << ans + min({c[0][n], c[0][k - 1], c[n - 1][n], c[n - 1][k - 1], c[n][0], c[n][n - 1], c[k - 1][0], c[k - 1][n - 1]}) << "\n";
        /*vector<vector<ll> > dist(k, vector<ll>(k, inf));
        auto comp = [&] (pii u, pii v) {
            int x1 = u.first, y1 = u.second;
            int x2 = v.first, y2 = v.second;
            if (dist[x1][y1] != dist[x2][y2]) {
                return dist[x1][y1] < dist[x2][y2];
            } else {
                return u < v;
            }
        };
        set<pii, decltype(comp)> q(comp);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = 0;
                q.insert({i, j});
            }
        }
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            pii v = *q.begin();
            q.erase(q.begin());
            int x = v.first, y = v.second;
            for (int i = 0; i < 4; ++i) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 0) {
                    xx += k;
                }
                if (xx >= k) {
                    xx -= k;
                }
                if (yy < 0) {
                    yy += k;
                }
                if (yy >= k) {
                    yy -= k;
                }
                if (dist[xx][yy] > dist[x][y] + c[xx][yy]) {
                    q.erase({xx, yy});
                    dist[xx][yy] = dist[x][y] + c[xx][yy];
                    q.insert({xx, yy});
                }
            }
        }
        ll minn = inf;
        for (int i = n; i < k; ++i) {
            for (int j = n; j < k; ++j) {
                minn = min(minn, dist[i][j]);
            }
        }
        cout << ans + minn << "\n";*/
    }

}