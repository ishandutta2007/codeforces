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

bool bit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<vector<ld> > a(n, vector<ld>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<ld> dp(1 << n);
    dp[(1 << n) - 1] = 1;
    for (int mask = (1 << n) - 1; mask; --mask) {
        vector<int> bits;
        for (int i = 0; i < n; ++i) {
            if (bit(mask, i)) {
                bits.pb(i);
            }
        }
        if (sz(bits) == 1) {
            continue;
        }
        ld b = sz(bits);
        ld prob = 2.0 / b / (b - 1);
        for (int i = 0; i < sz(bits); ++i) {
            for (int j = i + 1; j < sz(bits); ++j) {
                int x = bits[i], y = bits[j];
                dp[mask ^ (1 << x)] += dp[mask] * prob * a[y][x];
                dp[mask ^ (1 << y)] += dp[mask] * prob * a[x][y];
            }
        }
    }

    cout << fixed;
    cout.precision(12);
    for (int i = 0; i < n; ++i) {
        cout << dp[1 << i] << " ";
    }
    cout << "\n";

}