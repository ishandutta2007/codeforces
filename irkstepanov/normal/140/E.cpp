#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int mod;

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

const int nmax = 5050;

int F[nmax][nmax];
int P[nmax][nmax];
int fact[nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m >> mod;

    F[1][1] = m % mod;
    for (int l = 1; l + 1 < nmax; ++l) {
        for (int y = 1; y < nmax; ++y) {
            if (y + 1 < nmax) {
                int val = F[l][y];
                mul(val, (m - y) % mod);
                add(F[l + 1][y + 1], val);
            }
            int val = F[l][y];
            mul(val, (y - 1) % mod);
            add(F[l + 1][y], val);
        }
    }

    P[1][1] = 1;
    for (int l = 1; l + 1 < nmax; ++l) {
        for (int y = 1; y < nmax; ++y) {
            if (y + 1 < nmax) {
                int val = P[l][y];
                add(P[l + 1][y + 1], val);
            }
            int val = P[l][y];
            mul(val, (y - 1) % mod);
            add(P[l + 1][y], val);
        }
    }

    fact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
    }

    for (int l = 1; l < nmax; ++l) {
        for (int y = 1; y < nmax; ++y) {
            int p = P[l][y];
            P[l][y] = F[l][y];
            int val = p;
            mul(val, fact[y]);
            sub(P[l][y], val);
            if (y > l) {
                assert(P[l][y] == 0);
            }
        }
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> dp(1);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        int l = a[i];
        vector<int> nx(l + 1);
        for (int j = 0; j < sz(dp); ++j) {
            add(sum, dp[j]);
        }
        for (int y = 1; y <= l; ++y) {
            nx[y] = sum;
            if (y < sz(dp)) {
                sub(nx[y], dp[y]);
            }
            mul(nx[y], F[l][y]);
            if (y < sz(dp)) {
                int val = dp[y];
                mul(val, P[l][y]);
                add(nx[y], val);
            }
        }
        dp.swap(nx);
        cout << "\n";
    }

    int ans = 0;
    for (int i = 0; i < sz(dp); ++i) {
        add(ans, dp[i]);
    }

    cout << ans << "\n";

}