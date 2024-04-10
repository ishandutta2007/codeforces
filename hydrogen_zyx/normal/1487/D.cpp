#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double dinf = 1e99;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

vector<ll> v;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll l = 1, r = 1e9;
        double mid;
        while (l < r) {
            mid = (l + r + 1) >> 1;
            double ans = sqrt(mid * mid + (mid * mid - 1) / 2 * (mid * mid - 1) / 2);
            if (ans > n + 1e-7) r = mid - 1;
            else l = mid;
        }
        if (l < 3) {
            cout << 0 << endl;
            continue;
        }
        int ou = (l - 1) / 2;
        cout << ou << endl;
    }
}