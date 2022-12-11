#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int nmax = (int)5e5 + 100, inf = (int)1e9;
int v[nmax];

int dp[2][110][110];

int pref[nmax];

bool valid[nmax];
bool nx[nmax];

bool get(ull x, int pos) {
    ull z = (1LL << (pos + 1)) - 1;
    return (x & z);
}

bool is(ull x, ull y, int pos) {
    if (pos < 50) {
        return get(x, pos);
    } else {
        if (x) {
            return true;
        }
        return get(y, pos - 50);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, p;

    cin >> n >> k >> p;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (n <= p * k) {
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j < p; j++) {
                dp[0][i][j] = inf;
            }
        }

        dp[0][0][0] = 0;

        int it = 1;

        for (int ps = n - 1; ps >= 0; ps--) {
            for (int i = 0; i <= k; i++) {
                for (int j = 0; j < p; j++) {
                    dp[it][i][j] = dp[it ^ 1][i][(j + v[ps]) % p];

                    if (i != 0) {
                        dp[it][i][j] = min(dp[it][i][j], dp[it ^ 1][i - 1][0] + (j + v[ps]) % p);
                    }
                }
            }

            it ^= 1;
        }

        cout << dp[it ^ 1][k][0] << endl;
        return 0;
    }

    pref[0] = v[0] % p;
    for (int i = 1; i < n; ++i) {
        pref[i] = (pref[i - 1] + v[i]) % p;
    }

    int ans = p + pref[n - 1];
    for (int i = 0; i < n; ++i) {
        valid[i] = true;
    }

    for (int j = 2; j <= k; ++j) {
        ull x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            int val = pref[i];
            if (is(x, y, val)) {
                nx[i] = true;
            } else {
                nx[i] = false;
            }
            if (valid[i]) {
                if (pref[i] < 50) {
                    x |= (1LL << pref[i]);
                } else {
                    y |= (1LL << (pref[i] - 50));
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            valid[i] = nx[i];
        }
    }

    if (valid[n - 1]) {
        ans = min(ans, pref[n - 1]);
    }
    cout << ans << "\n";

}