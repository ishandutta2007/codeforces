#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef double ld;
typedef complex<ld> comp;

const int mod = 998244353;
const int root = 31;
const int maxdeg = 23;
int proot[maxdeg + 1];
int rroot[maxdeg + 1];

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
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

vector<int> rev;
int r2 = binpow(2, mod - 2);

void fft(vector<int>& a, int k, bool flag) {
    int n = (1 << k);
    assert(sz(a) == n);
    if (sz(rev) != n) {
        rev = vector<int>(n);
        int oldest = -1;
        rev[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (!(i & (i - 1))) {
                ++oldest;
            }
            rev[i] = rev[i ^ (1 << oldest)] + (1 << (k - oldest - 1));
        }
    }
    for (int i = 0; i < n; ++i) {
        if (rev[i] < i) {
            swap(a[i], a[rev[i]]);
        }
    }
    for (int r = 0; r < k; ++r) {
        int omega = (flag ? rroot[r + 1] : proot[r + 1]);
        int p = 1;
        for (int j = 0; j < (1 << r); ++j) {
            for (int i = j; i < n; i += (1 << (r + 1))) {
                int x = a[i], y = a[i + (1 << r)];
                mul(y, p);
                a[i] = x;
                add(a[i], y);
                a[i + (1 << r)] = x;
                sub(a[i + (1 << r)], y);
            }
            mul(p, omega);
        }
         /*for (int i = 0; i < n; i += (1 << (r + 1))) {
            int p = 1;
            for (int j = 0; j < (1 << r); ++j) {
                int x = a[i + j], y = a[i + j + (1 << r)];
                mul(y, p);
                a[i + j] = x;
                add(a[i + j], y);
                a[i + j + (1 << r)] = x;
                sub(a[i + j + (1 << r)], y);
                mul(p, omega);
            }
        }*/
    }
    if (flag) {
        int rn = binpow(n, mod - 2);
        for (int i = 0; i < n; ++i) {
            mul(a[i], rn);
        }
    }
}

const int buben = 4500;

vector<int> solve(vector<int> a, vector<int>& b, int n, int m, int k) {
    reverse(all(b));
    b.resize(1 << k);
    fft(b, k, false);
    for (int i = 0; i < sz(a); ++i) {
        mul(a[i], b[i]);
    }
    fft(a, k, true);
    vector<int> ans(n - m + 1);
    for (int i = m - 1; i < n; ++i) {
        int val = buben;
        sub(val, a[i]);
        mul(val, r2);
        ans[i - (m - 1)] = val;
    }
    return ans;
}

mt19937 rr(1);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");

    proot[maxdeg] = root;
    for (int i = maxdeg - 1; i >= 0; --i) {
        proot[i] = proot[i + 1];
        mul(proot[i], proot[i]);
    }
    for (int i = 0; i <= maxdeg; ++i) {
        rroot[i] = binpow(proot[i], mod - 2);
    }

    string a, b;
    cin >> a >> b;
    if (sz(b) < buben) {
        int q;
        cin >> q;
        while (q--) {
            int i, j, len;
            cin >> i >> j >> len;
            int ans = 0;
            while (len--) {
                ans += (a[i] != b[j]);
                ++i, ++j;
            }
            cout << ans << "\n";
        }
        return 0;
    }

    vector<vector<int> > products;
    int n = sz(a);
    vector<int> block(n);
    for (int i = 0; i < n; ++i) {
        block[i] = i / buben;
    }

    vector<int> vct2(sz(b));
    for (int i = 0; i < sz(b); ++i) {
        if (b[i] == '1') {
            vct2[i] = 1;
        } else {
            vct2[i] = mod - 1;
        }
    }

    int k = 0;
    while ((1 << k) <= sz(vct2) + buben) {
        ++k;
    }
    vct2.resize(1 << k);
    fft(vct2, k, false);

    for (int bl = 0; bl <= block.back(); ++bl) {
        vector<int> vct1;
        for (int i = bl * buben; i < bl * buben + buben && i < sz(a); ++i) {
            if (a[i] == '1') {
                vct1.pb(1);
            } else {
                vct1.pb(mod - 1);
            }
        }
        products.pb(solve(vct2, vct1, sz(b), sz(vct1), k));
    }

    int q;
    cin >> q;
    while (q--) {
        int i, j, len;
        cin >> i >> j >> len;
        int l = i, r = i + len - 1;
        int x = j, y = j + len - 1;
        int ans = 0;
        int rem = l % buben;
        while (l <= r && rem) {
            ans += (a[l] != b[x]);
            ++l, ++x;
            ++rem;
            if (rem == buben) {
                rem = 0;
            }
        }
        rem = r % buben;
        while (l <= r && rem != buben - 1) {
            ans += (a[r] != b[y]);
            --r, --y;
            --rem;
            if (rem == -1) {
                rem = buben - 1;
            }
        }
        if (l > r) {
            cout << ans << "\n";
            continue;
        }
        for (int bl = block[l]; bl <= block[r]; ++bl) {
            ans += products[bl][x];
            x += buben;
        }
        cout << ans << "\n";
    }

}