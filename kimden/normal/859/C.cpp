#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<ll> dp(n);
    vector<ll> suff(n);
    suff[n - 1] = a[n - 1];
    for(ll i = n - 2; i >= 0; --i){
        suff[i] = suff[i + 1] + a[i];
    }
    dp[n - 1] = a[n - 1];
    for(ll i = n - 2; i >= 0; --i){
        dp[i] = max(dp[i + 1], a[i] + suff[i + 1] - dp[i + 1]);
    }
    cout << suff[0] - dp[0] << " " << dp[0] << endl;
    return 0;
}