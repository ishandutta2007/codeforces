#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<int, ll> data;

const ll inf = 1e18;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<string> s(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        r[i] = s[i];
        reverse(all(r[i]));
    }

    vector<vector<ll> > dp(2, vector<ll>(n, inf));
    dp[0][0] = 0;
    dp[1][0] = c[0];
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] <= s[i]) {
            dp[0][i] = min(dp[0][i], dp[0][i - 1]);
        }
        if (r[i - 1] <= s[i]) {
            dp[0][i] = min(dp[0][i], dp[1][i - 1]);
        }
        if (s[i - 1] <= r[i]) {
            dp[1][i] = min(dp[1][i], dp[0][i - 1] + c[i]);
        }
        if (r[i - 1] <= r[i]) {
            dp[1][i] = min(dp[1][i], dp[1][i - 1] + c[i]);
        }
    }

    ll ans = min(dp[0][n - 1], dp[1][n - 1]);
    cout << (ans == inf ? -1 : ans) << "\n";

}