// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<int n>
struct mexer_small {
    ull a[n];

    mexer_small() { memset(a, 0, sizeof(a)); }
    void operator+= (int x) { a[x >> 6] |= 1ull << (x & 63); }
    int operator() () const {
        for (int i=0; i<n; i++) if (a[i] != ~0ull) return (i << 6) + __builtin_ctzll(~a[i]);
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a[2];
        cin >> a[0] >> a[1];

        vector<int> d(n+1);

        for (int j=1; j<=n; j++) {
            for (int l=0; l<=min(3, j); l++) {
                mexer_small<4> ms;
                for (int i=j-l; i<j; i++) {
                    ms += a[0][i] - '0';
                    ms += a[1][i] - '0';
                }

                d[j] = max(d[j], d[j-l] + ms());
            }
        }

        cout << d[n] << '\n';
    }
}