#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

const int inf = 1e9;

int dp[1050][1050][11][2];

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "r", stdin);

    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    string tmp1, tmp2;
    cin >> tmp1 >> tmp2;

    vector<char> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = tmp1[i - 1];
    }
    for (int i = 1; i <= m; ++i) {
        b[i] = tmp2[i - 1];
    }

    //vector<vector<vector<vector<int> > > > dp(n + 1, vector<vector<vector<int> > >(m + 1, vector<vector<int> >(k + 1, vector<int>(2))));
    //0 -- open, 1 -- close

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int t = 1; t <= k; ++t) {
                if (a[i] == b[j]) {
                    dp[i][j][t][0] = 1 + max(dp[i - 1][j - 1][t][0], dp[i - 1][j - 1][t - 1][1]);
                    dp[i][j][t][1] = dp[i][j][t][0];
                }
                dp[i][j][t][1] = max(dp[i][j][t][1], dp[i - 1][j][t][1]);
                dp[i][j][t][1] = max(dp[i][j][t][1], dp[i][j - 1][t][1]);
            }
        }
    }

    cout << dp[n][m][k][1] << "\n";

}