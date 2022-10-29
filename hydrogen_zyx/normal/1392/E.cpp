#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    ll p = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i & 1)
                cout << 0LL << ' ';
            else
                cout << (1LL << (i + j - 1)) << ' ';
        }
        cout << endl;
    }
    ll m;
    cin >> m;
    while (m--) {
        ll k;
        cin >> k;
        ll x = 1, y = 1;
        cout << 1 << ' ' << 1 << endl;
        for (ll i = 2; i <= n + n - 1; i++) {
            if ((k & (1LL << i)) ^ ((x & 1LL) << (i))) {
                y++;
            } else {
                x++;
            }
            cout << x << ' ' << y << endl;
        }
    }
}