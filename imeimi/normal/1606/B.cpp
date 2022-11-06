#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        ll x = 1, ans = 0;
        while (x < k) {
            ++ans;
            x <<= 1;
        }
        ans += (n - x + k - 1) / k;
        printf("%lld\n", ans);
    }
    return 0;
}