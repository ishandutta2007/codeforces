#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n, w, x, y, z;
    ll a, b, c, d, k, ans=0;
    string s1, s2;
    bool sad = false;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        ans = 0; d = 0;
        while(n--) {
            cin >> a;
            if(d > 0) ans = max(ans, (a*100-1)/k+1-d);
            d += a;
        }
        cout << ans << '\n';
    }
}