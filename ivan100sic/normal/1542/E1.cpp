// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

vector<int> inverzije[505];

int ad(int x, int y, int mod) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

int sub(int x, int y, int mod) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
    return x;
}

vector<int> prosiri(vector<int> a, int w, int mod) {
    int n = a.size();
    a.insert(a.begin(), 0);
    for (int i=1; i<=n; i++) {
        a[i] = ad(a[i], a[i-1], mod);
    }
    vector<int> b(n + w - 1);
    for (int i=0; i<n+w-1; i++) {
        int l = max(0, i+1-w);
        int r = min(i+1, n);
        b[i] = sub(a[r], a[l], mod);
    }
    return b;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, mod;
    cin >> n >> mod;

    inverzije[1] = {1};
    for (int i=2; i<=n; i++) {
        inverzije[i] = prosiri(inverzije[i-1], i, mod);
    }

    int sol = 0;
    for (int p=0; p<n-1; p++) {
        int mult = 1 % mod;
        for (int i=0; i<p; i++) {
            mult = mult * 1ll * (n - i) % mod;
        }

        int acc = 0;

        for (int d=1; d<=n-p-1; d++) {
            int mult = (n-p-d) % mod, t = 0, z = 0;
            for (int i=0; i<(int)inverzije[n-p-1].size(); i++) {
                int j = i - d - 1;
                if (j >= 0) {
                    t = ad(t, inverzije[n-p-1][j], mod);
                }
                z = ad(z, t * 1ll * inverzije[n-p-1][i] % mod, mod);
            }
            // cerr << "pd " << d << ' ' << mult << ' ' << z << '\n';
            acc = ad(acc, mult * 1ll * z % mod, mod);
        }

        // cerr << p << ' ' << mult << ' ' << acc << '\n';

        sol = ad(sol, mult * 1ll * acc % mod, mod);
    }
    cout << sol << '\n';
}