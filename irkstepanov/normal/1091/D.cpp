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

const int nmax = 1e6 + 100;

int fact[nmax];
int rfact[nmax];

int bin(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    int ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
    }
    for (int i = 0; i < nmax; ++i) {
        rfact[i] = binpow(fact[i], mod - 2);
    }

    int n;
    cin >> n;

    int ans = fact[n];
    for (int l = 1; l <= n - 2; ++l) {
        int val = bin(n, l);
        mul(val, fact[l]);
        mul(val, n - l - 1);
        mul(val, l);
        add(ans, val);
    }

    cout << ans << "\n";

}