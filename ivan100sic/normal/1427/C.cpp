// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct celeb {
    int t, x, y;
};

int r, n;
celeb a[100005];
int ja[100005], svi[100005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> r >> n;
    a[0] = {0, 1, 1};
    memset(ja, 192, sizeof(ja));
    memset(svi, 192, sizeof(svi));
    ja[0] = svi[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i].t >> a[i].x >> a[i].y;

        for (int j=i-1; j>=0 && j>=i-2*r; j--) {
            if (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) <= a[i].t - a[j].t) {
                ja[i] = max(ja[i], ja[j] + 1);
            }
        }

        if (i >= 2*r) {
            ja[i] = max(ja[i], svi[i - 2*r] + 1);
        }

        svi[i] = max(svi[i-1], ja[i]);
    }

    cout << svi[n] << "\n";
}