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

ll dp[22][12][12][5][5];

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n, t;
    cin >> n >> t;

    for (int a = 1; a < 5; ++a) {
        for (int b = 1; b < 5; ++b) {
            if (a != b) {
                dp[2][0][0][a][b] = 1;
            }
        }
    }

    for (int i = 2; i < n; ++i) {
        for (int k = 0; k <= t; ++k) for (int l = 0; l <= t - 1; ++l) {
            for (int a = 1; a < 5; ++a) {
                for (int b = 1; b < 5; ++b) {
                    if (a == b) {
                        continue;
                    }
                    for (int c = 1; c < 5; ++c) {
                        if (c == b) {
                            continue;
                        }
                        if (a > b && b < c) {
                            dp[i + 1][k][l + 1][b][c] += dp[i][k][l][a][b];
                        } else if (a < b && b > c) {
                            dp[i + 1][k + 1][l][b][c] += dp[i][k][l][a][b];
                        } else {
                            dp[i + 1][k][l][b][c] += dp[i][k][l][a][b];
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int a = 1; a < 5; ++a) {
        for (int b = 1; b < 5; ++b) {
            ans += dp[n][t][t - 1][a][b];
        }
    }

    cout << ans << "\n";

}