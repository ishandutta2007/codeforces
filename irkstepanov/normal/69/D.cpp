#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

const int nmax = 401;

int dp[nmax][nmax][2][2][2];

bool valid(int x, int y, int d) {
    return (x - 200) * (x - 200) + (y - 200) * (y - 200) <= d * d;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int x0, y0, n, d;
    cin >> x0 >> y0 >> n >> d;
    x0 += 200, y0 += 200;

    vector<pii> vct = {{1, 1}, {1, 0}, {0, 1}, {0, 0}};
    vector<int> dx(n), dy(n);
    for (int i = 0; i < n; ++i) {
        cin >> dx[i] >> dy[i];
    }

    for (pii& pp : vct) {
        int a = pp.first, b = pp.second;
        for (int x = nmax - 1; x >= 0; --x) {
            for (int y = nmax - 1; y >= 0; --y) {
                if (!valid(x, y, d)) {
                    continue;
                }
                for (int p = 0; p < 2; ++p) {
                    dp[x][y][p][a][b] = (p ^ 1);
                    if (a == 0 && dp[y][x][p ^ 1][b][1] == p) {
                        dp[x][y][p][a][b] = p;
                    }
                    for (int i = 0; i < n; ++i) {
                        int xx = x + dx[i], yy = y + dy[i];
                        if (xx >= nmax || yy >= nmax || !valid(xx, yy, d)) {
                            continue;
                        }
                        if (dp[xx][yy][p ^ 1][b][a] == p) {
                            dp[x][y][p][a][b] = p;
                        }
                    }
                }
            }
        }
    }

    //cout << "!" << dp[2 + 200][3 + 200][0][0][0] << endl;

    if (dp[x0][y0][0][0][0] == 0) {
        cout << "Anton\n";
    } else {
        cout << "Dasha\n";
    }

}