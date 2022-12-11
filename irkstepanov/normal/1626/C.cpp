#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const ll inf = 8e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<ll> pos(n), hp(n);
        for (int i = 0; i < n; ++i) {
            cin >> pos[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> hp[i];
        }
        vector<ll> dp(n, inf);
        for (int i = 0; i < n; ++i) {
            ll lf = inf;
            for (int j = 0; j <= i; ++j) {
                lf = min(lf, pos[j] - hp[j] + 1);
            }
            ll x = pos[i] - lf + 1;
            dp[i] = x * (x + 1) / 2;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ll lf = inf;
                for (int k = i + 1; k <= j; ++k) {
                    lf = min(lf, pos[k] - hp[k] + 1);
                }
                if (lf <= pos[i]) {
                    continue;
                }
                ll x = pos[j] - lf + 1;
                dp[j] = min(dp[j], dp[i] + x * (x + 1) / 2);
            }
        }
        cout << dp[n - 1] << "\n";
    }

}