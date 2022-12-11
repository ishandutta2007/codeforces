#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int nmax = 100500;
const ll inf = 1e18;

ll a[3][nmax];
ll dp[3][nmax];

int main()
{

    ///ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < nmax; ++j) {
            a[i][j] = dp[i][j] = -inf;
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    a[2][n + 1] = 0;

    dp[0][0] = 0;

    for (int j = 0; j <= n; ++j) {
        for (int i = 0; i < 3; ++i) {
            for (int k = 0; k < 3; ++k) {
                ll sum = 0;
                for (int t = min(k, i); t <= max(k, i); ++t) {
                    sum += a[t][j];
                }
                sum += a[k][j + 1];
                sum -= a[i][j];
                dp[k][j + 1] = max(dp[k][j + 1], dp[i][j] + sum);
            }
        }
        ll sum = 0;
        for (int i = 0; i < 3; ++i) {
            sum += a[i][j];
            sum += a[i][j + 1];
        }
        dp[2][j + 2] = max(dp[2][j + 2], dp[0][j] + sum + a[2][j + 2] - a[0][j]);
        dp[0][j + 2] = max(dp[0][j + 2], dp[2][j] + sum + a[0][j + 2] - a[2][j]);
    }

    cout << dp[2][n + 1] << "\n";

}