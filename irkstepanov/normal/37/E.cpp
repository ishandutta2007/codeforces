#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int inf = 1e9;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("correct.txt");

    int n, m;
    cin >> n >> m;

    vector<vector<char> > a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int ans = 100500;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vector<vector<int> > dist(n, vector<int>(m, inf));
            dist[i][j] = 0;
            deque<pii> q;
            q.push_back({i, j});
            while (!q.empty()) {
                pii p = q.front();
                q.pop_front();
                int x = p.first, y = p.second;
                for (int k = 0; k < 4; ++k) {
                    int xx = x + dx[k], yy = y + dy[k];
                    if (xx < 0 || xx >= n || yy < 0 || yy >= m) {
                        continue;
                    }
                    if (dist[xx][yy] != inf) {
                        continue;
                    }
                    if (a[xx][yy] == a[x][y]) {
                        dist[xx][yy] = dist[x][y];
                        q.push_front({xx, yy});
                    } else {
                        dist[xx][yy] = dist[x][y] + 1;
                        q.push_back({xx, yy});
                    }
                }
            }
            /*if (i == 1 && j == 2) {
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < m; ++y) {
                        cout << dist[x][y] << " ";
                    }
                    cout << "\n";
                }
            }*/
            int curr = 0;
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < m; ++y) {
                    if (a[x][y] == 'B') {
                        curr = max(curr, dist[x][y] + 1);
                    } /*else {
                        curr = max(curr, dist[x][y]);
                    }*/
                }
            }
            ans = min(ans, curr);
        }
    }

    cout << ans << "\n";

}