#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

const int mod = 8 * 9 * 5 * 7;

ll dp[2][2][2][2][3][4][mod];

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int gett[4][4][10];

int pw(int a, int b) {
    int ans = 1;
    while (b--) {
        ans *= a;
    }
    return ans;
}

ll solve(ll xx) {
    vector<int> dd;
    while (xx) {
        dd.pb(xx % 10);
        xx /= 10;
    }
    reverse(all(dd));
    memset(dp, 0, sizeof(dp));
    dp[0][1][0][0][0][0][0] = 1;
    int ptr = 0;
    for (int i = 0; i < sz(dd); ++i) {
        memset(dp[ptr ^ 1], 0, sizeof(dp[ptr ^ 1]));
        for (int r = 0; r < mod; ++r) {
            for (int a = 0; a < 2; ++a) {
                for (int b = 0; b < 2; ++b) {
                    for (int c = 0; c < 3; ++c) {
                        for (int d = 0; d < 4; ++d) {
                            if (dp[ptr][0][a][b][c][d][r] == 0 && dp[ptr][1][a][b][c][d][r] == 0) {
                                continue;
                            }
                            for (int z = 0; z < 10; ++z) {
                                int nr = (r * 10 + z) % mod;
                                int na = gett[0][a][z];
                                int nb = gett[1][b][z];
                                int nc = gett[2][c][z];
                                int nd = gett[3][d][z];
                                dp[ptr ^ 1][0][na][nb][nc][nd][nr] += dp[ptr][0][a][b][c][d][r];
                                if (z < dd[i]) {
                                    dp[ptr ^ 1][0][na][nb][nc][nd][nr] += dp[ptr][1][a][b][c][d][r];
                                }
                                if (z == dd[i]) {
                                    dp[ptr ^ 1][1][na][nb][nc][nd][nr] += dp[ptr][1][a][b][c][d][r];
                                }
                            }
                        }
                    }
                }
            }
        }
        ptr ^= 1;
    }
    ll ans = 0;
    for (int a = 0; a < 2; ++a) {
        for (int b = 0; b < 2; ++b) {
            for (int c = 0; c < 3; ++c) {
                for (int d = 0; d < 4; ++d) {
                    for (int r = 0; r < mod; ++r) {
                        bool ok = true;
                        if (r % pw(5, a)) {
                            ok = false;
                        }
                        if (r % pw(7, b)) {
                            ok = false;
                        }
                        if (r % pw(3, c)) {
                            ok = false;
                        }
                        if (r % pw(2, d)) {
                            ok = false;
                        }
                        if (ok) {
                            ans += dp[ptr][0][a][b][c][d][r] + dp[ptr][1][a][b][c][d][r];
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> p = {5, 7, 3, 2};

    for (int z = 0; z < 10; ++z) {
        for (int a = 0; a < 4; ++a) {
            for (int pos = 0; pos < 4; ++pos) {
                int cnt = 0;
                if (z) {
                    int val = z;
                    while (val % p[pos] == 0) {
                        ++cnt;
                        val /= p[pos];
                    }
                }
                gett[pos][a][z] = max(a, cnt);
            }
        }
    }

    int tt;
    cin >> tt;

    while (tt--) {
        ll l, r;
        cin >> l >> r;

        ll ans = solve(r) - solve(l - 1);
        cout << ans << "\n";
    }

}