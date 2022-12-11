#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int nmax = 200500;

int dp[3][3][nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        if (i) {
            for (int a = 0; a < 3; ++a) {
                for (int b = 0; b < 3; ++b) {
                    if (a == b) {
                        continue;
                    }
                    int c = 3 - a - b;
                    dp[a][b][i] = dp[a][b][i - 1];
                    if (i % 3 == 0) {
                        dp[a][b][i] += (s[i] - 'a' != a);
                    } else if (i % 3 == 1) {
                        dp[a][b][i] += (s[i] - 'a' != b);
                    } else {
                        dp[a][b][i] += (s[i] - 'a' != c);
                    }
                }
            }
        } else {
            for (int a = 0; a < 3; ++a) {
                for (int b = 0; b < 3; ++b) {
                    if (a == b) {
                        continue;
                    }
                    dp[a][b][i] = (s[i] - 'a' != a);
                }
            }
        }
    }

    //cout << "!" << dp[2][0][n - 1] << " " << dp[2][1][n - 1] << endl;

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int ans = nmax;
        for (int a = 0; a < 3; ++a) {
            for (int b = 0; b < 3; ++b) {
                if (a == b) {
                    continue;
                }
                int val = dp[a][b][r];
                if (l) {
                    val -= dp[a][b][l - 1];
                }
                ans = min(ans, val);
            }
        }
        cout << ans << "\n";
    }
    
}