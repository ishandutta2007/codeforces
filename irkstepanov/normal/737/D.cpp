#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int kmax = 70;

const ll inf = 1e18;

int main()
{

    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> pref(n + 1), suff(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        suff[i] = suff[i - 1] + a[n - i + 1];
    }

    vector<vector<vector<ll> > > dp(n + 1, vector<vector<ll> >(kmax, vector<ll>(kmax)));

    for (int x = n; x >= 0; --x) {
        for (int k = kmax - 1; k >= 0; --k) {
            for (int d = k - 1; d >= 0; --d) {
                int y = x + d;
                if (x + y + k > n) {
                    dp[x][k][d] = pref[x] - suff[y];
                } else {
                    ll step1;
                    ll g = inf;
                    if (x + y + k + k <= n) {
                        g = min(g, dp[x + k][k][d]);
                    }
                    if (x + y + k + (k + 1) <= n && k + 1 < kmax && d + 1 < kmax) {
                        g = min(g, dp[x + k][k + 1][d + 1]);
                    }
                    if (g == inf) {
                        step1 = pref[x + k] - suff[y];
                    } else {
                        step1 = g;
                    }

                    ll step2 = -inf;
                    if (x + y + (k + 1) <= n) {
                        g = inf;
                        if (x + y + (k + 1) + (k + 1) <= n && k + 1 < kmax) {
                            g = min(g, dp[x + k + 1][k + 1][d]);
                        }
                        if (x + y + (k + 1) + (k + 2) <= n && k + 2 < kmax && d + 1 < kmax) {
                            g = min(g, dp[x + k + 1][k + 2][d + 1]);
                        }
                        if (g == inf) {
                            step2 = pref[x + k + 1] - suff[y];
                        } else {
                            step2 = g;
                        }
                    }

                    dp[x][k][d] = max(step1, step2);
                }
            }
        }
    }

    cout << dp[0][1][0] << '\n';

}