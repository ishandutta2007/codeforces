#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int mod = 31607;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

int binpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        n >>= 1;
        mul(a, a);
    }
    return ans;
}

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void solve(int n, vector<int>& cnew, int factor, bool retract, int cnt, int& ans) {
    int val = 1;
    for (int j = 0; j < n; ++j) {
        int curr = 1;
        sub(curr, cnew[j]);
        mul(val, curr);
    }

    if (retract) {
        sub(val, 1);
    }

    mul(val, factor);

    if (cnt & 1) {
        add(ans, val);
    } else {
        sub(ans, val);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    int ans = 0;
    int den = binpow(10000, mod - 2);

    vector<vector<int> > a(n, vector<int>(n));
    vector<vector<int> > rev(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            mul(a[i][j], den);
            rev[i][j] = binpow(a[i][j], mod - 2);
        }
    }

    vector<int> c(n, 1), r(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mul(r[i], a[i][j]);
            mul(c[j], a[i][j]);
        }
    }

    vector<vector<int> > store(1 << n, vector<int>(n));
    int oldest = -1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (mask == 0) {
            store[mask] = c;
            continue;
        }
        if (!(mask & (mask - 1))) {
            ++oldest;
        }
        store[mask] = store[mask ^ (1 << oldest)];
        for (int j = 0; j < n; ++j) {
            mul(store[mask][j], rev[oldest][j]);
        }
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> cnew = store[mask];
        /*for (int i = 0; i < n; ++i) {
            if (bit(mask, i)) {
                for (int j = 0; j < n; ++j) {
                    mul(cnew[j], rev[i][j]);
                }
            }
        }*/

        int factor = 1;
        for (int i = 0; i < n; ++i) {
            if (bit(mask, i)) {
                mul(factor, r[i]);
            }
        }

        // NO DIAGONAL
        solve(n, cnew, factor, (mask == 0), __builtin_popcount(mask), ans);

        // LEFT DIAGONAL
        for (int j = 0; j < n; ++j) {
            if (!bit(mask, j)) {
                mul(cnew[j], rev[j][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!bit(mask, i)) {
                mul(factor, a[i][i]);
            }
        }

        solve(n, cnew, factor, false, __builtin_popcount(mask) + 1, ans);

        for (int i = 0; i < n; ++i) {
            if (!bit(mask, i)) {
                mul(factor, rev[i][i]);
            }
        }
        for (int j = 0; j < n; ++j) {
            if (!bit(mask, j)) {
                mul(cnew[j], a[j][j]);
            }
        }

        // RIGHT DIAGONAL
        for (int j = 0; j < n; ++j) {
            if (!bit(mask, n - j - 1)) {
                mul(cnew[j], rev[n - j - 1][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!bit(mask, i)) {
                mul(factor, a[i][n - i - 1]);
            }
        }

        solve(n, cnew, factor, false, __builtin_popcount(mask) + 1, ans);

        for (int j = 0; j < n; ++j) {
            if (!bit(mask, n - j - 1)) {
                mul(cnew[j], a[n - j -1][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!bit(mask, i)) {
                mul(factor, rev[i][n - i - 1]);
            }
        }

        // BOTH DIAGONALS
        for (int j = 0; j < n; ++j) {
            if (!bit(mask, j)) {
                mul(cnew[j], rev[j][j]);
            }
            if (!bit(mask, n - j - 1) && j != n - j - 1) {
                mul(cnew[j], rev[n - j - 1][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!bit(mask, i)) {
                int d = a[i][i];
                if (i != n - i - 1) {
                    mul(d, a[i][n - i - 1]);
                }
                mul(factor, d);
            }
        }

        solve(n, cnew, factor, false, __builtin_popcount(mask) + 2, ans);
    }

    cout << ans << "\n";
    
}