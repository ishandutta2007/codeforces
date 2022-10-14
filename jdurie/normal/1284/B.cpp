#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

vector<ll> firs, las;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin >> n;
    ll ans = n * n;
    for(ll e = 0; e < n; e++) {
        ll m, mn = LLONG_MAX, fir = -1;
        bool asc = false;
        cin >> m;
        for(ll i = 0; i < m; i++) {
            ll x; cin >> x;
            if(fir == -1) fir = x;
            if(x > mn) asc = true;
            else mn = x;
        }
        if(asc) continue;
        firs.push_back(fir);
        las.push_back(mn);
    }
    sort(firs.begin(), firs.end());
    for(ll l : las)
        if(l >= firs[0])  {
            ans -= firs.size() - (firs.end() - upper_bound(firs.begin(), firs.end(), l));
        }
    cout << ans << endl;
}