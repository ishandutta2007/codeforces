#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

ll a[N+5];

ll calc(ll x, ll k){
    k++;
    ll y = x/k;
    ll z = x%k;
    return y*y*(k-z) + (y+1)*(y+1)*z;
}

pair <ll, ll> check(int n, ll k){
    ll sumd = 0, pt = 0;
    for(int i=1; i<=n; i++){
        ll l = 1, r = a[i] - 1, res = 0;
        while(l <= r){
            ll mid = (l+r)/2;
            ll f = calc(a[i], mid);
            ll s = calc(a[i], mid - 1);
            if(s - f >= k){
                l = mid + 1;
                res = mid;
            }
            else{
                r = mid - 1;
            }
        }
        pt += res;
        sumd += calc(a[i], res);
    }
    return {sumd, pt};
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    ll l = 1, r = a[n]*a[n];
    for(int i=n; i>=2; i--) a[i] -= a[i-1];
    ll m;
    cin >> m;
    pair <ll, ll> res = {a[n], a[n] - n};
    ll bd = 1;
    while(l <= r){
        ll mid = (l+r)/2;
        pair <ll, ll> h = check(n, mid);
        if(h.first <= m){
            res = h;
            bd = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    if(res.second >= 1) cout << res.second - (m - res.first)/bd << "\n";
    else cout << 0 << "\n";
    return 0;
}