#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int mod = 1e9 + 7;

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
    ll c = ll(a) * ll(b);
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

typedef vector<vector<int> > matrix;

matrix operator*(const matrix& a, const matrix& b) {
    int n = sz(a), k = sz(a[0]), m = sz(b[0]);
    matrix c(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int z = 0; z < k; ++z) {
                int val = a[i][z];
                mul(val, b[z][j]);
                add(c[i][j], val);
            }
        }
    }
    return c;
}

matrix binpow(matrix a, ll n) {
    int k = sz(a);
    matrix ans(k, vector<int>(k));
    for (int i = 0; i < k; ++i) {
        ans[i][i] = 1;
    }
    while (n) {
        if (n & 1) {
            ans = ans * a;
        }
        n >>= 1;
        a = a * a;
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    ll d;
    cin >> q >> d;

    const int n = 16;
    matrix ans(n, vector<int>(1));
    ans[0][0] = 1;

    matrix m(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (abs(i - j) <= 1) {
                m[i][j] = 1;
            }
        }
    }

    for (int tt = 0; tt < q; ++tt) {
        ll lf, rg;
        cin >> lf >> rg;
        ll val;
        cin >> val;
        for (int i = val + 1; i < n; ++i) {
            ans[i][0] = 0;
        }
        if (rg > d) {
            rg = d;
        }
        matrix base = m;
        for (int i = val + 1; i < n; ++i) {
            base[i] = vector<int>(n, 0);
        }
        base = binpow(base, rg - lf);
        ans = base * ans;
    }

    cout << ans[0][0] << "\n";

}