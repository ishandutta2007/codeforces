#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll n, k, m;
    cin >> n >> k >> m;
    ll D;
    cin >> D;
    ll res = 0;
    for(ll d=1; d<=D; d++){
        if(n/k < d-1) continue;
        ll x = n/(k*(d-1) + 1);
        x = min(m, x);
        if(x == 0) continue;
        ll dd = (n/x+k-1)/k;
        if(dd == d) res = max(res, x*d);
    }
    cout << res;
    return 0;
}