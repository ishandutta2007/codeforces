#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 1;
const int P = 10;

vector <pair<int, int> > v[P];
int d[P][N][N], bg[P], u[P];
string s[N];

int main() {
    int i, j, k, n, l, r, p;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> p;
    for (i = 1; i <= p; ++i) {
        cin >> u[i];
        u[i] = min(u[i], (int)1e6);
    }
    for (l = 1; l <= p; ++l)
    for (i = 0; i < n; ++i)
    for (j = 0; j < k; ++j)
            d[l][i][j] = -1;
    for (i = 0; i < n; ++i) {
        cin >> s[i];
        for (j = 0; j < k; ++j)
        if (s[i][j] >= '0' && s[i][j] <= '9') {
            v[s[i][j] - '0'].push_back({i, j});
            d[s[i][j] - '0'][i][j] = 0;
        }
    }
    for (int h = 1; h <= n * k; ++h) {
        for (l = 1; l <= p; ++l) {
            i = bg[l];
            while (i < v[l].size() && d[l][v[l][i].fi][v[l][i].se] < h * u[l]) {
                int x = v[l][i].fi, y = v[l][i].se;
                for (int i1 = -1; i1 <= 1; ++i1)
                for (int j1 = -1; j1 <= 1; ++j1) {
                if (abs(i1) + abs(j1) == 1 && x + i1 >= 0 && x + i1 < n && y + j1 >= 0 && y + j1 < k && s[x + i1][y + j1] == '.' && d[l][x + i1][y + j1] == -1) {
                    s[x + i1][y + j1] = l + '0';
                    v[l].push_back({x + i1, y + j1});
                    d[l][x + i1][y + j1] = d[l][x][y] + 1;
                }
                }
                ++i;
            }
            bg[l] = i;
        }
    }
    for (l = 1; l <= p; ++l) {
        int ans = 0;
        for (i = 0; i < n; ++i)
        for (j = 0; j < k; ++j)
        if (s[i][j] == l + '0')
            ++ans;
        cout << ans << ' ';
    }
}