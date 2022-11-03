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
    sort(a.begin(), a.end());
    map<ll, ll> mp;
    for(ll i = 0; i < n && a[i] <= a[2]; ++i){
        ++mp[a[i]];
    }
    ll ans = 1;
    if(mp.size() == 1){
        ans = mp[a[0]] * 1LL * (mp[a[0]] - 1LL) * 1LL * (mp[a[0]] - 2LL);
        ans /= 6;
    }else{
        if(mp.size() == 2){
            if(mp[a[0]] == 1){
                ans = mp[a[2]] * 1LL * (mp[a[2]] - 1LL);
                ans /= 2;
            }else{
                ans = mp[a[2]];
            }
        }else{
            ans = mp[a[2]];
        }
    }
    cout << ans << endl;
    return 0;
}