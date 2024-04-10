#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n, u, v, x=-1, y=-1;
    ll k, ans = 0;
    string s1, s2;
    int sad = 0;
    cin >> t;
    while(t--) {
        x = y = -1;
        sad = 0;
        cin >> n >> u >> v;
        while(n--) {
            cin >> x;
            if(y == -1) y = x;
            sad = max(sad, abs(x-y));
            y = x;
        }
        if(sad == 0) cout << min(u+v, v+v) << '\n';
        if(sad == 1) cout << min(u, v) << '\n';
        if(sad > 1) cout << 0 << '\n';
    }
}