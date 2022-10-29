#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
ll a[3][200000];
ll ca, cb, cc;
ll suan(ll aa, ll b, ll c) {
    if (aa > ca || b > cb || c > cc) return 0xffffffffffffffff;
    return (a[0][aa] - a[1][b]) * (a[0][aa] - a[1][b]) +
           (a[0][aa] - a[2][c]) * (a[0][aa] - a[2][c]) +
           (a[1][b] - a[2][c]) * (a[1][b] - a[2][c]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        cin >> ca >> cb >> cc;
        for (int i = 1; i <= ca; i++) cin >> a[0][i];
        for (int i = 1; i <= cb; i++) cin >> a[1][i];
        for (int i = 1; i <= cc; i++) cin >> a[2][i];
        sort(a[0] + 1, a[0] + 1 + ca);
        sort(a[1] + 1, a[1] + 1 + cb);
        sort(a[2] + 1, a[2] + 1 + cc);
        ll p0 = 1, p1 = 1, p2 = 1;
        ll mmin = suan(1, 1, 1);
        while (p0 < ca || p1 < cb || p2 < cc) {
            ll a0 = suan(p0 + 1, p1, p2);
            ll a1 = suan(p0, p1 + 1, p2);
            ll a2 = suan(p0, p1, p2 + 1);
            if (a0 <= a1 && a0 <= a2) {
                mmin = min(mmin, a0);
                p0++;
            } else if (a1 <= a0 && a1 <= a2) {
                mmin = min(mmin, a1);
                p1++;
            } else {
                mmin = min(mmin, a2);
                p2++;
            }
        }
        cout << mmin << endl;
    }
}