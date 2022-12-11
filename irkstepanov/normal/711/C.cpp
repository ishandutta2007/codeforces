#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef long double ld;

const ll inf = 1e18;

int main()
{

    //ifstream cin("input.txt");

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    vector<vector<ll> > cost(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> cost[i][j];
        }
    }

    vector<vector<vector<ll> > > dp(n + 1, vector<vector<ll> >(m + 1, vector<ll>(k + 1, inf)));
    dp[0][0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int last = 0; last <= m; ++last) {
            for (int cnt = 0; cnt <= k; ++cnt) {
                if (c[i + 1]) {
                    int new_cnt = cnt + int(last != c[i + 1]);
                    if (new_cnt <= k) {
                        dp[i + 1][c[i + 1]][new_cnt] = min(dp[i + 1][c[i + 1]][new_cnt], dp[i][last][cnt]);
                    }
                    continue;
                }
                for (int color = 1; color <= m; ++color) {
                    int new_cnt = cnt + int(last != color);
                    if (new_cnt <= k) {
                        dp[i + 1][color][new_cnt] = min(dp[i + 1][color][new_cnt], dp[i][last][cnt] + cost[i + 1][color]);
                    }
                }
            }
        }
    }

    ll ans = inf;
    for (int color = 1; color <= m; ++color) {
        ans = min(ans, dp[n][color][k]);
    }
    cout << (ans == inf ? -1 : ans) << "\n";

}