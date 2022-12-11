#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;

int cnt[10];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    vector<int> d;
    while (n) {
        d.pb(n % 10);
        n /= 10;
    }

    n = sz(d);

    vector<vector<int> > dp(n, vector<int>(2, -1));
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            if ((x + y) % 10 == d[0]) {
                dp[0][(x + y) / 10] = max(dp[0][(x + y) / 10], x + y);
            }
        }
    }

    for (int i = 1; i < sz(d); ++i) {
        for (int c = 0; c < 2; ++c) {
            if (dp[i - 1][c] == -1) {
                continue;
            }
            for (int x = 0; x < 10; ++x) {
                for (int y = 0; y < 10; ++y) {
                    if ((x + y + c) % 10 == d[i]) {
                        int z = (x + y + c) / 10;
                        dp[i][z] = max(dp[i][z], dp[i - 1][c] + x + y);
                    }
                }
            }
        }
    }

    cout << dp[n - 1][0] << "\n";
    
}