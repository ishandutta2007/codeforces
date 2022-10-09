// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

// T*F*
template<class T>
int count_true(int l, int r, T pred) {
    int l0 = l;
    int o = l - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (pred(m)) {
            o = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return o + 1 - l0;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        vector<ll> s(n), ks(n);
        s[0] = a[0];
        for (int i=1; i<n; i++) {
            s[i] = s[i-1] + a[i];
        }
        ks[0] = a[0];
        ks[1] = a[1];
        for (int i=2; i<n; i++) {
            ks[i] = ks[i-2] + a[i];
        }

        ll sol = 0, limit = (s[n-1] - 1) / 2;

        // length at least 3, with or without the last one, without last two
        for (ll last_delta : {0, a[n-1]}) {
            int ub = last_delta == 0 ? n-2 : n-3;
            // odd length
            for (int i=2; i<=ub; i+=2) {
                // x?x?x?x
                sol += count_true(0, i/2, [&](int m) { return last_delta + ks[i] + (m ? ks[2*m-1] : 0) <= limit; });
            
                // .xx?x?x
                sol += count_true(1, i/2, [&](int m) { return last_delta + ks[i] - a[0] + ks[2*m-1] <= limit; });
            }

            for (int i=1; i<=ub; i+=2) {
                // .x?x?x
                sol += count_true(0, i/2, [&](int m) { return last_delta + ks[i] + ks[2*m] - a[0] <= limit; });

                // xx?x?x
                sol += count_true(0, i/2, [&](int m) { return last_delta + ks[i] + ks[2*m] <= limit; });
            }
        }

        // trivials
        sol += 0 <= limit;
        sol += a[0] <= limit;
        sol += a[n-1] <= limit;
        sol += a[0] + a[n-1] <= limit;

        // c-suffix, at least two
        for (int l=2; l<n; l++) {
            sol += s[n-1] - s[n-1-l] <= limit;
        }

        cout << sol % 998'244'353 << '\n';
    }
}