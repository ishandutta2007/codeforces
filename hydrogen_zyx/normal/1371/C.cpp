#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        ll sub = abs(a - b);
        sub = min(sub, n);
        a > b ? a -= sub : b -= sub;
        n -= sub;
        if (min(a, b) < m) {
            cout << "NO" << endl;
            continue;
        } else {
            if (a + b >= n + m)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}