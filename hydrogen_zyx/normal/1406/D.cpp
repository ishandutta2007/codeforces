#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200000];
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i > 1; i--) {
        a[i] = a[i] - a[i - 1];
    }
    ll a1 = a[1], a2 = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] > 0) a2 += a[i];
    }

    if (a1 + a2 > 0) {
        cout << (a1 + a2 + 1) / 2 << endl;
    } else {
        cout << (a1 + a2) / 2 << endl;
    }
    ll q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        ll l, r, x;
        cin >> l >> r >> x;
        if (l == 1) a1 += x;
        ll p1, p2;
        if (a[l] > 0)
            p1 = a[l];
        else
            p1 = 0;
        if (r != n && a[r + 1] > 0)
            p2 = a[r + 1];
        else
            p2 = 0;
        ll n1, n2;
        a[l] += x;
        a[r + 1] -= x;
        if (a[l] > 0)
            n1 = a[l];
        else
            n1 = 0;
        if (r != n && a[r + 1] > 0)
            n2 = a[r + 1];
        else
            n2 = 0;
        a2 = a2 - p2 + n2;
        if (l != 1) a2 = a2 - p1 + n1;
        if (a1 + a2 > 0) {
            cout << (a1 + a2 + 1) / 2 << endl;
        } else {
            cout << (a1 + a2) / 2 << endl;
        }
    }
}