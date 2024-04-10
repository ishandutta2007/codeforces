#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double dinf = 1e99;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[N];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        k--;
        ll ans;
        if (n & 1) ans = (k * 2 % (n - 1) - k % n + n) % n + 1;
        else
            ans = k % n + 1;
        cout << ans << endl;
    }
}