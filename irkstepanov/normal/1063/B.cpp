#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 2010;

char s[nmax][nmax];
pii dp[nmax][nmax];
const int inf = 1e9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int x, y;
    cin >> x >> y;
    int lf, rg;
    cin >> lf >> rg;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j].first = inf;
        }
    }
    --x, --y;
    deque<pii> q;
    q.push_front({x, y});
    dp[x][y] = {0, 0};

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop_front();
        for (int k = 0; k < 4; ++k) {
            int xx = x + dx[k], yy = y + dy[k];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m || s[xx][yy] == '*') {
                continue;
            }
            if (dp[xx][yy].first != inf) {
                continue;
            }
            int a = dp[x][y].first, b = dp[x][y].second;
            if (k == 2) {
                ++a;
            } else if (k == 3) {
                ++b;
            }

            if (a <= lf && b <= rg) {
                dp[xx][yy] = {a, b};
                if (a + b == dp[x][y].first + dp[x][y].second) {
                    q.push_front({xx, yy});
                } else {
                    q.push_back({xx, yy});
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dp[i][j].first != inf) {
                ++ans;
            }
        }
    }
    cout << ans << "\n";
    
}