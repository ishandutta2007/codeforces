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

const int nmax = 5050 * 2;
const int kmax = 500;

int bin[nmax][kmax];

int get(int s, int n) {
    if (s == 0) {
        if (n >= 0) {
            return 1;
        } else {
            return 0;
        }
    }
    if (s < 0) {
        return 0;
    }
    if (n == 0) {
        return 0;
    }
    return bin[s + n - 1][n - 1];
}

int solve(int s, int n, int m) {
    if (m == -1) {
        if (s == 0 && n == 0) {
            return 1;
        }
        return 0;
    }
    if (s == 0) {
        return 1;
    }
    if (m * n < s) {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i <= n && s >= i * (m + 1); ++i) {
        int val = 1;
        if (i & 1) {
            val = mod - 1;
        }
        mul(val, bin[n][i]);
        mul(val, get(s - i * (m + 1), n));
        add(ans, val);
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bin[0][0] = 1;
    for (int i = 1; i < nmax; ++i) {
        bin[i][0] = 1;
        for (int j = 1; j < kmax; ++j) {
            bin[i][j] = bin[i - 1][j];
            add(bin[i][j], bin[i - 1][j - 1]);
        }
    }

    int n, s, r;
    cin >> n >> s >> r;

    int num = 0;
    int den = 0;
    for (int x = r; x <= s; ++x) {
        for (int t = 0; (t + 1) * x <= s && t <= n - 1; ++t) {
            int val = solve(s - (t + 1) * x, n - 1 - t, x - 1);
            mul(val, bin[n - 1][t]);
            mul(val, binpow(t + 1, mod - 2));
            add(num, val);
        }
        add(den, get(s - x, n - 1));
    }

    mul(num, binpow(den, mod - 2));
    cout << num << "\n";

}