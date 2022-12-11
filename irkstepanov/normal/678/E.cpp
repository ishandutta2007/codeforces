#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld eps = 1e-9;

bool lt(ld a, ld b)
{
    return b - a > eps;
}

bool bit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "r", stdin);

    int n;
    cin >> n;
    vector<vector<ld> > p(n, vector<ld>(n));

    fori {
        forj {
            cin >> p[i][j];
        }
    }

    vector<vector<ld> > dp(n, vector<ld>(1 << n));

    dp[0][0] = 1.0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int f = 0; f < n; ++f) {
            if (bit(mask, f)) {
                continue;
            }
            ld ans = 0;
            for (int i = 0; i < n; ++i) {
                if (bit(mask, i)) {
                    ld prob = p[f][i] * dp[f][mask ^ (1 << i)] + p[i][f] * dp[i][mask ^ (1 << i)];
                    if (lt(ans, prob)) {
                        ans = prob;
                    }
                }
            }
            dp[f][mask] = ans;
        }
    }

    cout << fixed;
    cout.precision(12);
    ld ans = 0;
    for (int i = 0; i < n; ++i) {
        ld val = dp[i][((1 << n) - 1) ^ (1 << i)];
        if (lt(ans, val)) {
            ans = val;
        }
    }

    cout << ans << "\n";

}