#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll a, b;
    ll ans = 999999999;
    for(a = 1; a <= n; ++a){
        ld x = ceil(n * 1. / a);
        b = (ll)x;
        ans = min(ans, 2 * (a + b));
    }
    cout << ans << endl;
    return 0;
}