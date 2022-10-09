// Retired?
#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct my_bitset {
    ull a[96];
    void set(uint32_t x) {
        a[x >> 6] |= 1ull << (x & 63);
    }

    int xor_cnt(const my_bitset& b) {
        int z = 0;
        for (int i=0; i<96; i++) {
            z += __builtin_popcountll(a[i] ^ b.a[i]);
        }
        return z;
    }

    bool operator[](uint32_t x) {
        return (a[x >> 6] >> (x & 63)) & 1;
    }
};

int n, x[6005], y[6005];
my_bitset a[6005];

void read_input() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
}

void generate_input() {
    n = 6000;
    for (int i=0; i<n; i++) {
        x[i] = 4*i;
        y[i] = 4*i*i; // not strictly good but who cares
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    read_input();

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int p = abs(x[i] - x[j]);
            int q = abs(y[i] - y[j]);
            // 2 or 4
            if ((p & 3) == 0 && (q & 3) == 0) {
                a[i].set(j);
                a[j].set(i);
            }
        }
    }

    ll sol = 0;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int c = a[i].xor_cnt(a[j]);
            if (a[i][j]) {
                sol += n - c;
            } else {
                sol += c;
            }
        }
    }

    cout << sol / 3 << '\n';
}