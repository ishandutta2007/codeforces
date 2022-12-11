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
typedef pair<int, int> pii;
typedef long double ld;

const int mod = 1e9 + 7;

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

void neg(int& a) {
    a = mod - a;
    if (a >= mod) {
        a -= mod;
    }
}

const int nmax = 500500;

int fact[nmax];
int rfact[nmax];
int rev[nmax];

int bin(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    int ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int stirling(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    int ans = 0;
    for (int j = 0; j <= k; ++j) {
        int val = bin(k, j);
        mul(val, binpow(j, n));
        if ((k + j) % 2) {
            neg(val);
        }
        add(ans, val);
    }
    mul(ans, rfact[k]);
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    rev[1] = 1;
    for (int i = 2; i < nmax; ++i) {
        int val = mod / i;
        mul(val, rev[mod % i]);
        neg(val);
        rev[i] = val;
    }

    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = rfact[i - 1];
        mul(rfact[i], rev[i]);
    }

    int n, k;
    cin >> n >> k;

    int c = stirling(n, k);
    int d = stirling(n - 1, k);
    mul(d, n - 1);
    add(c, d);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        add(sum, x);
    }
    mul(c, sum);

    cout << c << endl;

}