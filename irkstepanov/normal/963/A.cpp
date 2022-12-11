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

const int mod = 1e9 + 9;

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
        n >>= 1;
        mul(a, a);
    }
    return ans;
}

int solve(int a, int q, int s) {
    if (s == 1) {
        return a;
    }
    if (s & 1) {
        int b = a;
        mul(b, q);
        int ans = solve(b, q, s - 1);
        add(ans, a);
        return ans;
    } else {
        int ans = solve(a, q, s / 2);
        int f = binpow(q, s / 2);
        add(f, 1);
        mul(ans, f);
        return ans;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, k;
    cin >> n >> a >> b >> k;
    ++n;

    string t;
    cin >> t;

    int s = n / k;
    int q = binpow(b, k);
    mul(q, binpow(binpow(a, mod - 2), k));
    int val = solve(1, q, s);

    mul(val, binpow(a, n - 1));
    int ra = binpow(a, mod - 2);

    int ans = 0;
    for (int i = 0; i < k; ++i) {
        if (t[i] == '-') {
            sub(ans, val);
        } else {
            add(ans, val);
        }
        mul(val, b);
        mul(val, ra);
    }

    cout << ans << "\n";

}