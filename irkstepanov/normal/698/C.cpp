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
typedef pair<ll, ll> pll;

const ld eps = 1e-9;

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool bit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ld> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    cout << fixed;
    cout.precision(12);

    for (int i = 0; i < n; ++i) {
        vector<ld> dp(1 << n);
        dp[0] = p[i];
        if (eq(p[i], 0)) {
            cout << "0.0\n";
            continue;
        }
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (bit(mask, i)) {
                continue;
            }
            bool ok = true;
            for (int b = 0; b < n; ++b) {
                if (bit(mask, b) && eq(p[b], 0)) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }
            if (mask) {
                ld sum = 0;
                for (int b = 0; b < n; ++b) {
                    if (bit(mask, b)) {
                        sum += p[b];
                    }
                }
                if (eq(sum, 1)) {
                    dp[mask] = 1.0;
                } else {
                    dp[mask] /= (1 - sum);
                }
            }
            for (int b = 0; b < n; ++b) {
                if (b != i && !bit(mask, b)) {
                    dp[mask | (1 << b)] += p[b] * dp[mask];
                }
            }
        }
        ld ans = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            int cnt = 0;
            for (int b = 0; b < n; ++b) {
                if (b != i && bit(mask, b)) {
                    ++cnt;
                }
            }
            if (cnt < k) {
                ans += dp[mask];
            }
        }
        cout << ans << "\n";
    }

}