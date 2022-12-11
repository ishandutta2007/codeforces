#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

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

const int root = 31;
const int kmax = 23;
const int kk = 21;

int rev[1 << kmax];
int degs[kmax];
int rdeg[kmax];

void fft(vector<int>& a, bool flag) {
    int n = sz(a);
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
                int x = a[i + j];
                int y = a[i + j + len / 2];
                mul(y, w);
                a[i + j] = a[i + j + len / 2] = x;
                add(a[i + j], y);
                sub(a[i + j + len / 2], y);
                mul(w, step);
            }
        }
    }
    if (flag) {
        int rn = binpow(n, mod - 2);
        for (int i = 0; i < n; ++i) {
            mul(a[i], rn);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    rev[0] = 0;
    int oldest = -1;
    for (int i = 1; i < (1 << kk); ++i) {
        if (!(i & (i - 1))) {
            ++oldest;
        }
        rev[i] = (rev[i ^ (1 << oldest)] | (1 << (kk - oldest - 1)));
    }

    degs[0] = root;
    for (int i = 1; i < kmax; ++i) {
        degs[i] = degs[i - 1];
        mul(degs[i], degs[i]);
    }

    for (int i = 0; i < kmax; ++i) {
        rdeg[i] = binpow(degs[i], mod - 2);
    }

    int n, z;
    cin >> n >> z;
    n /= 2;

    vector<int> ops;
    while (n > 1) {
        if (n % 2) {
            ops.pb(1);
            --n;
        } else {
            ops.pb(2);
            n /= 2;
        }
    }

    reverse(all(ops));

    vector<int> f(1 << kk);
    while (z--) {
        int d;
        cin >> d;
        f[d] = 1;
    }

    vector<int> init;
    fft(f, false);
    init = f;

    for (int o : ops) {
        if (o == 2) {
            for (int i = 0; i < (1 << kk); ++i) {
                mul(f[i], f[i]);
            }
        } else {
            for (int i = 0; i < (1 << kk); ++i) {
                mul(f[i], init[i]);
            }
        }
    }

    fft(f, true);

    int ans = 0;
    for (int i = 0; i < (1 << kk); ++i) {
        int val = f[i];
        mul(val, val);
        add(ans, val);
    }
    cout << ans << "\n";

}