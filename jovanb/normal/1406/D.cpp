#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll a[100005];

ll calc(ll x){
    return max(0LL, a[x]);
}

const ll INF = 1000000000000000LL;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ll n;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
    }
    ll res = 0;
    a[0] = -INF;
    for(ll i=n; i>=1; i--){
        a[i] -= a[i-1];
    }
    a[n+1] = -INF;
    for(ll i=1; i<=n; i++){
        res += calc(i);
    }
    if(res-INF >= 0) cout << (res+1-INF)/2 << "\n";
    else cout << (res-INF)/2 << "\n";
    ll q;
    cin >> q;
    while(q--){
        ll l, r, x;
        cin >> l >> r >> x;
        res -= calc(l);
        res -= calc(r+1);
        a[l] += x;
        a[r+1] -= x;
        res += calc(l);
        res += calc(r+1);
        if(res-INF >= 0) cout << (res+1-INF)/2 << "\n";
        else cout << (res-INF)/2 << "\n";
    }
    return 0;
}