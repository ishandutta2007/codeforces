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

vector<int> ps(vector<int> a, int mod) {
    int n = a.size();
    a.insert(a.begin(), 0);
    for (int i=1; i<=n; i++) {
        a[i] = ad(a[i], a[i-1], mod);
    }
    return a;
}

vector<int> prosiri(vector<int> a, int w, int mod) {
    int n = a.size();
    a = ps(a, mod);
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
    for (int p=0; p<=n-4; p++) {
        int mult = 1 % mod;
        for (int i=0; i<p; i++) {
            mult = mult * 1ll * (n - i) % mod;
        }

        int acc = 0;

        // pomnozi sa (n-p-1)x + (n-p-2)x^2 + ... + 2 x^(n-p-2) + x^(n-p-1)
        // xxxxxxxxxxxx
        // 12345^
        //  12345^
        //   12345^

        auto v = inverzije[n-p-1];
        auto f = ps(v, mod);
        int rolling = 0, sumrol = 0;

        for (int i=0; i+1<(int)v.size(); i++) {
            // dodaj na zbir
            // cerr << "rolling sum " << i << ' ' << rolling << ' ' << v[i+1] << '\n';
            sumrol = ad(sumrol, rolling, mod);
            acc = ad(acc, sumrol * 1ll * v[i+1] % mod, mod);
            // prilagodi zbir
            rolling = sub(rolling, sub(f[i], i >= (n-p-1) ? f[i-(n-p-1)] : 0, mod), mod);
            rolling = ad(rolling, (n-p-1ll) * v[i] % mod, mod);
        }

        sol = ad(sol, mult * 1ll * acc % mod, mod);
    }
    cout << sol << '\n';
}

// 1 2 2 1