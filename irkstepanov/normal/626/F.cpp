#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int main()
{

    //ifstream cin("input.txt");

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(all(v));

    vector<vector<ll> > dp1(n, vector<ll>(k + 1));
    vector<vector<ll> > dp2(n, vector<ll>(k + 1));

    if (n >= 2) {
        dp1[1][0] = 1;
    }
    dp1[0][0] = 1;

    for (int i = 0; i < n - 1; ++i) {
        for (int g = 0; g < n; ++g) {
            for (int s = 0; s <= k; ++s) {
                int t = g * (v[i + 1] - v[i]);
                if (s + t > k) {
                    continue;
                }
                //cout << i << " " << g << " " << s << " " << t << " " << dp[i][g][s] << "\n";
                add(dp2[g][s + t], dp1[g][s]); ///group of one person
                if (g < n - 1) {
                    add(dp2[g + 1][s + t], dp1[g][s]); ///open group of i
                }
                if (g) {
                    add(dp2[g - 1][s + t], (dp1[g][s] * (ll)(g)) % mod); ///close one group
                    add(dp2[g][s + t], (dp1[g][s] * (ll)(g)) % mod); ///add him to one of groups
                }
            }
        }
        dp1.swap(dp2);
        for (int g = 0; g < n; ++g) {
            dp2[g].assign(k + 1, 0);
        }
    }

    ll ans = 0;
    for (int s = 0; s <= k; ++s) {
        add(ans, dp1[0][s]);
    }
    cout << ans << "\n";

}