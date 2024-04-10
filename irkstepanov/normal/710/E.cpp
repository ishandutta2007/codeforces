#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, int> pll;

const ll inf = 1e18;

int main()
{

    int n;
    ll x, y;
    cin >> n >> x >> y;

    vector<ll> dp(n + 1, inf);
    dp[0] = 0;
    dp[1] = x;

    for (int i = 2; i <= n; ++i) {
        if (i & 1) {
            dp[i] = min(x + dp[i - 1], x + y + dp[(i + 1) / 2]);
        } else {
            dp[i] = min(y + dp[i / 2], x + dp[i - 1]);
        }
    }

    cout << dp[n] << "\n";

}