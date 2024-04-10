#include <bits/stdc++.h>
#include <string.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps = 1e-5;

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<ld> > dp(n, vector<ld>(m));
    for (int j = 0; j < m; ++j) {
        dp[n - 1][j] = 0;
    }

    for (int i = n - 2; i >= 0; --i) {
        if (m == 1) {
            dp[i][0] = 2 + dp[i + 1][0];
        } else if (m == 2) {
            dp[i][0] = dp[i][1] = 3 + dp[i + 1][0];
        } else {
            vector<ld> a(m), b(m);
            a[1] = 0.5, b[1] = (3 + dp[i + 1][0]) / 2.0;
            for (int j = 1; j < m - 1; ++j) {
                a[j + 1] = 1.0 / (3 - a[j]);
                b[j + 1] = (4 + b[j] + dp[i + 1][j]) / (3 - a[j]);
            }
            vector<ld> x(m);
            dp[i][m - 1] = (dp[i + 1][m - 1] + 3 + b[m - 1]) / (2 - a[m - 1]);
            for (int j = m - 2; j >= 0; --j) {
                dp[i][j] = a[j + 1] * dp[i][j + 1] + b[j + 1];
            }
        }
    }

    /*for (int i = 0; i < n - 1; ++i) {
        if (!eq(dp[i][0], 1 + (dp[i][0] + dp[i][1] + dp[i + 1][0]) / 3)) {
            cout << "bad " << i << " " << 0 << "\n";
        }
        if (!eq(dp[i][m - 1], 1 + (dp[i][m - 1] + dp[i][m - 2] + dp[i + 1][m - 1]) / 3)) {
            cout << "bad " << i << " " << m - 1 << "\n";
        }
        for (int j = 1; j < m - 1; ++j) {
            if (!eq(dp[i][j], 1 + (dp[i][j] + dp[i][j - 1] + dp[i][j + 1] + dp[i + 1][j]) / 4)) {
                cout << "bad " << i << " " << j << "\n";
            }
        }
    }*/

    cout << fixed;
    cout.precision(12);

    int a, b;
    cin >> a >> b;
    --a, --b;
    cout << dp[a][b] << "\n";

}