#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

void computePrimesLargest(int n, std::vector<int> &largest)
{
    largest.resize(n + 1);
    std::iota(largest.begin(), largest.end(), 0);

    for (int i = 2; i <= n; i++) {
        if (i == largest[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                largest[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;

    vector<int> largest;
    computePrimesLargest(100'000, largest);
    vector<int> smallest_occ(100'000, n);

    vector<vector<int>> upto(17, vector<int>(n));
    int best = n;
    for (int i = n-1; i >= 0; i--) {
        while (v[i] > 1) {
            int p = largest[v[i]];
            v[i] /= p;
            while (v[i] % p == 0)
                v[i] /= p;
            best = min(best, smallest_occ[p]);
            smallest_occ[p] = i;
        }
        upto[0][i] = best;
    }
    for (int log = 1; log < 17; log++) {
        for (int i = 0; i < n; i++) {
            int x = upto[log-1][i];
            if (x == n)
                upto[log][i] = n;
            else
                upto[log][i] = upto[log-1][x];
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        int c = 0;
        for (int log = 16; log >= 0; log--) {
            if (upto[log][l] < r) {
                c += 1 << log;
                l = upto[log][l];
            }
        }
        cout << c + 1 << '\n';
    }
}