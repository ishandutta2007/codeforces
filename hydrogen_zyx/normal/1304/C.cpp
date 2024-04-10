#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll low = m, up = m;
        ll timeb = 0;
        bool success = 1;
        for (ll i = 0; i < n; i++) {
            ll timea, l, u;
            cin >> timea >> l >> u;
            ll d = timea - timeb;
            timeb = timea;
            up += d;
            low -= d;
            if (low > u || up < l) {
                success = 0;
            } else {
                up = min(up, u);
                low = max(low, l);
            }
        }
        if (success)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}