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

const ll inf = 1e18;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> dp(n + 1, inf);
    ll ans = inf;
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        int t;
        ll c;
        cin >> t >> c;
        ++t;
        for (int j = n; j >= 0; --j) {
            if (j + t >= n) {
                ans = min(ans, dp[j] + c);
            } else {
                dp[j + t] = min(dp[j + t], dp[j] + c);
            }
        }
    }

    cout << ans << "\n";

}