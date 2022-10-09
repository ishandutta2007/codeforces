// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[5005], p[5005];

int run(int x) {
    if (x >= n) return x;
    int r = run(p[x]);
    if (a[x] == 1) {
        return p[x] = r;
    } else {
        a[x]--;
        p[x] = a[x] + x;
        return x;
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            p[i] = i + a[i];
        }

        ll z = 0;

        for (int i=0; i<n; i++) {
            if (a[i] > n) {
                z += a[i] - n;
                a[i] = n;
            }

            while (a[i] != 1) {
                z++;
                run(i);
            }
        }

        cout << z << '\n';
    }
}