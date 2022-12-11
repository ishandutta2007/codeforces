#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ifstream cin("input.txt");

    int n;
    cin >> n;

    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }

    vector<vector<int> > dp(n, vector<int>(n, n));

    forn(i, n) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len - 1;
            for (int x = i; x < j; ++x) {
                dp[i][j] = min(dp[i][j], dp[i][x] + dp[x + 1][j]);
            }
            if (a[i] == a[j]) {
                if (i == j - 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                }
            }
        }
    }

    cout << dp[0][n - 1] << "\n";

}