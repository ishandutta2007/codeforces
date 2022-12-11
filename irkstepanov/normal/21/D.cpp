 #include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const int inf = 1e9;

bool bit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > d(n, vector<int>(n, inf));
    vector<int> deg(n);
    vector<int> used(n);
    for (int i = 0; i < n; ++i) {
        d[i][i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        ++used[u], ++used[v];
        if (u == v) {
            ans += w;
            continue;
        }
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
        ans += w;
        ++deg[u], ++deg[v];
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        if (d[0][i] == inf && used[i]) {
            cout << "-1\n";
            return 0;
        }
    }

    vector<int> dp(1 << n);
    for (int mask = 1; mask < (1 << n); ++mask) {
        int f = -1;
        for (int i = 0; i < n; ++i) {
            if (bit(mask, i) && (deg[i] & 1)) {
                f = i;
                break;
            }
        }
        dp[mask] = inf;
        for (int j = 0; j < n; ++j) {
            if (bit(mask, j) && (deg[j] & 1) && j != f) {
                dp[mask] = min(dp[mask], d[f][j] + dp[mask - (1 << j) - (1 << f)]);
            }
        }
    }

    int mask = 0;
    for (int i = 0; i < n; ++i) {
        if (deg[i] & 1) {
            mask |= (1 << i);
        }
    }
    cout << ans + dp[mask] << "\n";

}