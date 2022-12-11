#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

const int mod = int(1e9) + 7;

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

void xorConvolution(vector<int>& a, int k, bool inv = false) {
    for (int lvl = 0; lvl < k; ++lvl) {
        for (int i = 0; i < (1 << k); i += (1 << (lvl + 1))) {
            for (int j = i; j < i + (1 << lvl); ++j) {
                int x = a[j], y = a[j + (1 << lvl)];
                a[j] = a[j + (1 << lvl)] = x;
                add(a[j], y);
                sub(a[j + (1 << lvl)], y);
            }
        }
    }
    if (inv) {
        int val = binpow(1 << k, mod - 2);
        for (int i = 0; i < (1 << k); ++i) {
            mul(a[i], val);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    string s;
    cin >> s;

    vector<int> a(1 << k);
    for (int i = 0; i < (1 << k); ++i) {
        a[i] = (s[i] - '0');
    }

    xorConvolution(a, k);
    for (int i = 0; i < (1 << k); ++i) {
        mul(a[i], a[i]);
    }

    xorConvolution(a, k, true);
    int ans = 0;
    for (int z = 0; z < (1 << k); ++z) {
        int val = (1 << (k - __builtin_popcount(z)));
        mul(val, a[z]);
        add(ans, val);
    }
    mul(ans, 3);
    cout << ans << "\n";
    
}