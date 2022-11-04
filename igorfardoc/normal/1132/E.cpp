#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll w;
    cin >> w;
    vector<ll> a(8);
    for(int i = 0; i < 8; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for(int mask = 0; mask < (1 << 24); mask++) {
        ll now = 0;
        for(int i = 7; i >= 0; i--) {
            int val = (mask >> (i * 3)) & 7;
            ll can = min(a[i], (w - now) / (i + 1));
            can = max(0ll, can - val);
            now += can * (i + 1);
        }
        ans = max(ans, now);
    }
    cout << ans;
}