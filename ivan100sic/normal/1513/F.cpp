// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct seg {
    int l, r, t;

    bool operator< (const seg& o) const {
        return l < o.l;
    }
};

int n;
int a[200005], b[200005];
seg s[200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;

    ll old = 0;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    for (int i=0; i<n; i++) {
        if (a[i] > b[i]) {
            s[i] = {b[i], a[i], 1};
        } else {
            s[i] = {a[i], b[i], 0};
        }
        old += abs(a[i] - b[i]);
    }

    sort(s, s+n);
    int r[2] = {0, 0};
    int sec = 0;
    for (int i=0; i<n; i++) {
        sec = max(sec, min(s[i].r, r[1^s[i].t]) - s[i].l);
        r[s[i].t] = max(r[s[i].t], s[i].r);
    }

    cout << old - 2*sec << '\n';
}