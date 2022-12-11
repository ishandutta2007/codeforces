#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int nmax = 2010;

const int mod = 998244353;

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
        mul(a, a);
        n >>= 1;
    }
    return ans;
}

const int kmax = 23;

int degs[kmax];
int rdeg[kmax];

const int kk = 12;

int rev[1 << kk];

void fft(vector<int>& a, bool flag) {
    int n = sz(a);
    assert(n == (1 << kk));
    for (int i = 0; i < n; ++i) {
        int j = rev[i];
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    for (int len = 2, t = 1; len <= n; len <<= 1, ++t) {
        int step = degs[kmax - t];
        if (flag) {
            step = rdeg[kmax - t];
        }
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int x = a[i + j], y = a[i + j + len / 2];
                mul(y, w);
                a[i + j + len / 2] = x;
                add(a[i + j], y);
                sub(a[i + j + len / 2], y);
                mul(w, step);
            }
        }
    }
    if (flag) {
        int r = binpow(n, mod - 2);
        for (int i = 0; i < n; ++i) {
            mul(a[i], r);
        }
    }
}

int f[nmax][nmax];
int bin[nmax][nmax];
int fact[nmax];
int a[nmax][nmax];
int dp[nmax];

class ST {
public:
    ST(int n) {
        t.resize(2 * nmax);
        for (int i = 0; i < nmax; ++i) {
            if (i < n) {
                t[i + nmax] = 1;
            } else {
                t[i + nmax] = 0;
            }
        }
        for (int i = nmax - 1; i; --i) {
            t[i] = t[i * 2] + t[i * 2 + 1];
        }
    }

    void upd(int pos, int val) {
        pos += nmax;
        t[pos] = val;
        for (pos >>= 1; pos; pos >>= 1) {
            t[pos] = t[pos * 2] + t[pos * 2 + 1];
        }
    }

    int get(int l, int r) {
        int ans = 0;
        for (l += nmax, r += nmax; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if (l & 1) {
                ans += t[l];
            }
            if (!(r & 1)) {
                ans += t[r];
            }
        }
        return ans;
    }
private:
    vector<int> t;
};

int pw[nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
    }

    bin[0][0] = 1;
    for (int i = 1; i < nmax; ++i) {
        bin[i][0] = 1;
        for (int j = 1; j < nmax; ++j) {
            bin[i][j] = bin[i - 1][j];
            add(bin[i][j], bin[i - 1][j - 1]);
        }
    }

    degs[0] = 31;
    for (int i = 1; i < kmax; ++i) {
        degs[i] = degs[i - 1];
        mul(degs[i], degs[i]);
    }

    for (int i = 0; i < kmax; ++i) {
        rdeg[i] = binpow(degs[i], mod - 2);
    }

    int oldest = -1;
    rev[0] = 0;
    for (int i = 1; i < (1 << kk); ++i) {
        if (!(i & (i - 1))) {
            ++oldest;
        }
        rev[i] = (rev[i ^ (1 << oldest)] | (1 << (kk - 1 - oldest)));
    }

    vector<int> facts(1 << kk);
    int val = 1;
    for (int i = 0; i < (1 << kk); ++i) {
        facts[i] = val;
        mul(val, i + 1);
    }
    fft(facts, false);

    for (int k = 0; k < nmax; ++k) {
        vector<int> poly(1 << kk);
        for (int l = 0; l <= k; ++l) {
            val = 1;
            if (l & 1) {
                val = mod - 1;
            }
            mul(val, bin[k][l]);
            poly[l] = val;
        }
        fft(poly, false);
        for (int i = 0; i < (1 << kk); ++i) {
            mul(poly[i], facts[i]);
        }
        fft(poly, true);
        for (int n = k; n < nmax; ++n) {
            f[n][k] = poly[n];
        }
    }

    dp[0] = 1;
    for (int n = 1; n < nmax; ++n) {
        int ans = fact[n];
        for (int j = 1; j <= n; ++j) {
            int val = fact[n - j];
            mul(val, bin[n][j]);
            if (j & 1) {
                mul(val, mod - 1);
            }
            add(ans, val);
        }
        dp[n] = ans;
    }

    int n;
    cin >> n;

    pw[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        pw[i] = pw[i - 1];
        mul(pw[i], dp[n]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            --a[i][j];
        }
    }

    int ans = 0;
    ST t(n);

    for (int j = 0; j < n; ++j) {
        int cnt = t.get(0, a[0][j] - 1);
        mul(cnt, fact[n - j - 1]);
        mul(cnt, pw[n - 1]);
        add(ans, cnt);
        t.upd(a[0][j], 0);
    }

    // Piece of piss +++

    for (int i = 1; i < n; ++i) {
        vector<int> lf(n), rg(n);
        ST t1(n), t2(n);
        // t1[j] = true, if j in the right is alive
        // t2[j] = true, if j in the right is alive as well as rg[j]
        for (int j = 0; j < n; ++j) {
            lf[j] = a[i - 1][j];
            rg[a[i - 1][j]] = j;
        }

        vector<bool> occ(n, false);
        int b = n;
        for (int j = 0; j < n; ++j) {
            int cnt = t1.get(0, a[i][j] - 1);
            int tot = 0;
            if (a[i][j] > lf[j] && !occ[lf[j]]) {
                int y = t2.get(0, a[i][j] - 1) - 1;
                if (y) {
                    val = y;
                    mul(val, f[n - j - 1][b - 2]);
                    add(tot, val);
                    mul(val, pw[n - i - 1]);
                    add(ans, val);
                }
                val = cnt - y - 1;
                mul(val, f[n - j - 1][b - 1]);
                add(tot, val);
                mul(val, pw[n - i - 1]);
                add(ans, val);
            } else if (occ[lf[j]]) {
                int y = t2.get(0, a[i][j] - 1);
                if (y) {
                    val = y;
                    mul(val, f[n - j - 1][b - 1]);
                    add(tot, val);
                    mul(val, pw[n - i - 1]);

                    add(ans, val);
                }
                val = cnt - y;
                mul(val, f[n - j - 1][b]);
                add(tot, val);
                mul(val, pw[n - i - 1]);
                add(ans, val);
            } else {
                int y = t2.get(0, a[i][j] - 1);
                if (y) {
                    val = y;
                    mul(val, f[n - j - 1][b - 2]);
                    add(tot, val);
                    mul(val, pw[n - i - 1]);
                    add(ans, val);
                }
                val = cnt - y;
                mul(val, f[n - j - 1][b - 1]);
                add(tot, val);
                mul(val, pw[n - i - 1]);
                add(ans, val);
            }

            /*vector<int> p(n);
            for (int u = 0; u < n; ++u) {
                p[u] = u;
            }
            int found = 0;
            do {
                bool ok = true;
                for (int u = 0; u < j; ++u) {
                    if (p[u] != a[i][u]) {
                        ok = false;
                        break;
                    }
                }
                if (p[j] >= a[i][j]) {
                    ok = false;
                }
                for (int u = 0; u < n; ++u) {
                    if (p[u] == a[i - 1][u]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ++found;
                }
            } while (next_permutation(all(p)));

            if (found != tot) {
                cout << i << " " << j << " " << tot << " " << found << endl;
                cout << "KEK\n";
            }*/

            t1.upd(a[i][j], 0);
            if (t2.get(a[i][j], a[i][j])) {
                --b;
            }
            t2.upd(a[i][j], 0);
            if (t2.get(lf[j], lf[j])) {
                --b;
            }
            t2.upd(lf[j], 0);
            occ[a[i][j]] = true;

        }
    }

    cout << ans << "\n";

}