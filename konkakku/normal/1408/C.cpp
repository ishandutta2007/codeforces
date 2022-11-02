#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, te, l, r, a[N];

double calc(double pl, double sl, double tl, double pr, double sr, double tr) {
    double dif = tr - tl;
    pr += 1.0 * dif * sr;
    return tl + (pr - pl) / (sl + sr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    cin >> te;
    while (te--) {
        cin >> n >> a[n + 1];
        int l = 0, r = n + 1;
        double tl = 0.0, tr = 0.0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        while (true) {
            int sl = l + 1;
            int sr = n + 2 - r;
            double nl = tl + 1.0 * (a[l + 1] - a[l]) / sl;
            double nr = tr + 1.0 * (a[r] - a[r - 1]) / sr;
            double nm = calc(a[l], sl, tl, a[r], sr, tr);
            double mi = min(min(nl, nr), nm);
            if (mi == nm) {
                cout << nm << '\n';
                break;
            } else if (mi == nl) {
                tl = nl;
                l++;
            } else {
                tr = nr;
                r--;
            }
        }
    }
}