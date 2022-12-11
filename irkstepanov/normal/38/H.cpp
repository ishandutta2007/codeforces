#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

const int nmax = 55;
const int inf = 1e9;

int dist[nmax][nmax];
ll dp[nmax][nmax];
ll nx[nmax][nmax];

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }

    while (m--) {
        int u, v;
        int c;
        cin >> u >> v >> c;
        --u, --v;
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int g1, g2, s1, s2;
    cin >> g1 >> g2 >> s1 >> s2;
    for (int i = 0; i < n; ++i) {
        sort(dist[i], dist[i] + n);
    }

    ll ans = 0;
    for (int gg = 0; gg < n; ++gg) {
        for (int bb = 0; bb < n; ++bb) {
            if (gg == bb) {
                continue;
            }
            pii p = {dist[gg][1], gg};
            pii q = {dist[bb][n - 1], bb};
            memset(dp, 0, sizeof(dp));
            dp[1][0] = 1;
            for (int i = 0; i < n; ++i) {
                if (i == gg || i == bb) {
                    continue;
                }
                memset(nx, 0, sizeof(nx));
                bool gold = false, silver = false, bronze = false;
                for (int j = 1; j < n; ++j) {
                    pii curr = {dist[i][j], i};
                    if (curr < p) {
                        gold = true;
                    }
                    if (curr > p && curr < q) {
                        silver = true;
                    }
                    if (curr > q) {
                        bronze = true;
                    }
                }
                for (int a = 1; a <= g2; ++a) {
                    for (int b = 0; b <= s2; ++b) {
                        if (gold && a + 1 <= g2) {
                            nx[a + 1][b] += dp[a][b];
                        }
                        if (silver && b + 1 <= s2) {
                            nx[a][b + 1] += dp[a][b];
                        }
                        if (bronze) {
                            nx[a][b] += dp[a][b];
                        }
                    }
                }
                memcpy(dp, nx, sizeof(dp));
            }
            for (int a = g1; a <= g2; ++a) {
                for (int b = s1; b <= s2; ++b) {
                    ans += dp[a][b];
                }
            }
        }
    }

    cout << ans << "\n";

}