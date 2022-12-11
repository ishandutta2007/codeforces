#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n, k;
    ll l;
    cin >> n >> l >> k;

    vector<ll> d(n), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll> > dp(n, vector<ll>(n, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int del = 0; del < n; ++del) {
            if (dp[i][del] == inf) {
                continue;
            }
            for (int nx = i + 1; nx < n; ++nx) {
                ll val = dp[i][del] + (d[nx] - d[i]) * a[i];
                dp[nx][del + nx - i - 1] = min(dp[nx][del + nx - i - 1], val);
            }
        }
    }

    ll ans = inf;
    for (int i = 0; i < n; ++i) {
        for (int del = 0; del < n; ++del) {
            if (dp[i][del] == inf) {
                continue;
            }
            int total = del + n - i - 1;
            if (total > k) {
                continue;
            }
            ans = min(ans, dp[i][del] + (l - d[i]) * a[i]);
        }
    }
    cout << ans << "\n";

}