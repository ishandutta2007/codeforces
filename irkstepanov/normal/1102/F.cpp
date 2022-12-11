#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int inf = 1e9;
const int nmax = 16;

int dp[nmax][nmax][1 << nmax];

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    if (n == 1) {
        int ans = inf;
        for (int j = 1; j < m; ++j) {
            ans = min(ans, abs(a[0][j - 1] - a[0][j]));
        }
        cout << ans << "\n";
        return 0;
    }

    vector<vector<int> > g(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            int val = inf;
            for (int k = 0; k < m; ++k) {
                val = min(val, abs(a[i][k] - a[j][k]));
            }
            g[i][j] = val;
        }
    }

    for (int i = 0; i < n; ++i) {
        dp[i][i][1 << i] = inf;
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int st = 0; st < n; ++st) {
            if (!bit(mask, st)) {
                continue;
            }
            for (int fi = 0; fi < n; ++fi) {
                if (!bit(mask, fi)) {
                    continue;
                }
                for (int to = 0; to < n; ++to) {
                    if (bit(mask, to)) {
                        continue;
                    }
                    int nmask = (mask | (1 << to));
                    dp[st][to][nmask] = max(dp[st][to][nmask], min(dp[st][fi][mask], g[fi][to]));
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            int val = inf;
            for (int k = 0; k + 1 < m; ++k) {
                val = min(val, abs(a[i][k] - a[j][k + 1]));
            }
            g[i][j] = val;
        }
    }

    int mask = (1 << n) - 1;

    int opt = 0;
    for (int st = 0; st < n; ++st) {
        for (int fi = 0; fi < n; ++fi) {
            opt = max(opt, min(dp[st][fi][mask], g[fi][st]));
        }
    }

    cout << opt << "\n";

}