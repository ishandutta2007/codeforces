// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct prod {
    ll a, b;

    bool operator< (const prod& o) const {
        return b < o.b;
    }
};

int n;
prod a[100005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i].a >> a[i].b;
    }

    sort(a, a+n);

    ll z = 0, b = 0;
    for (int i=0, j=n-1; i<n; i++) {
        while (a[i].a > 0) {
            if (b >= a[i].b) {
                z += a[i].a;
                b += a[i].a;
                a[i].a = 0;
                break;
            }

            ll d = min({a[j].a, a[i].b - b, a[i].a});
            a[j].a -= d;
            z += 2 * d;
            b += d;
            if (a[j].a == 0 && j >= 0) {
                j--;
            }
        }
    }

    cout << z << '\n';
}