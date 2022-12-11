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

int main()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    int n, x;
    cin >> n >> x;

    vector<int> c(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    vector<vector<int> > dp(n + 1, vector<int>(x + 1, -100500));
    for (int i = 1; i <= n; ++i) {
        for (int rest = x; rest >= (n - i + 1) * c[i]; --rest) {
            int rnew = rest - (n - i + 1) * c[i];
            dp[i][rnew] = 1;
            for (int j = 0; j < i; ++j) {
                dp[i][rnew] = max(dp[i][rnew], dp[j][rest] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";

}