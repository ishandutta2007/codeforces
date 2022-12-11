#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main()
{

    //ifstream cin("input.txt");

    int n, m, k;
    cin >> n >> m >> k;
    ++k;

    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }

    vector<vector<vector<int> > > dp(n, vector<vector<int> >(m, vector<int>(k, -1)));
    vector<vector<vector<int> > >  p(n, vector<vector<int> >(m, vector<int>(k, -1)));

    for (int j = 0; j < m; ++j) {
        dp[n - 1][j][a[n - 1][j] % k] = a[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m; ++j) {
            for (int d = 0; d < k; ++d) {
                int x = (d - a[i][j]) % k;
                if (x < 0) {
                    x += k;
                }
                if (j >= 1 && dp[i + 1][j - 1][x] != -1) {
                    dp[i][j][d] = dp[i + 1][j - 1][x] + a[i][j];
                    p[i][j][d] = j - 1;
                }
                if (j < m - 1 && dp[i + 1][j + 1][x] != -1 && dp[i + 1][j + 1][x] + a[i][j] > dp[i][j][d]) {
                    dp[i][j][d] = dp[i + 1][j + 1][x] + a[i][j];
                    p[i][j][d] = j + 1;
                }
            }
        }
    }

    int j = -1;
    int ans = -1;
    for (int t = 0; t < m; ++t) {
        if (dp[0][t][0] > ans) {
            ans = dp[0][t][0];
            j = t;
        }
    }

    if (ans == -1) {
        cout << ans << "\n";
        return 0;
    }
    cout << ans << "\n";
    vector<int> v;
    v.pb(j);
    int x = 0;
    for (int i = 0; i < n - 1; ++i) {
        int xnew = (x - a[i][j]) % k;
        if (xnew < 0) {
            xnew += k;
        }
        j = p[i][j][x];
        v.pb(j);
        x = xnew;
    }

    cout << j + 1 << "\n";
    for (int i = sz(v) - 2; i >= 0; --i) {
        int t = v[i];
        if (t == j - 1) {
            cout << "L";
        } else {
            cout << "R";
        }
        j = t;
    }

}