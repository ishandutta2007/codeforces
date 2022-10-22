#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007;

ll add(ll a, ll b){
    return (a+b)%MOD;
}

ll mul(ll a, ll b){
    return ((ll)a*b)%MOD;
}

ll pw(ll a, ll b){
    if(b == 0) return 1;
    ll res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ll x, k;
    cin >> x >> k;
    if(x == 0){
        cout << 0;
        return 0;
    }
    x %= MOD;
    ll res = mul(x, pw(2, k+1));
    res = add(res, MOD-pw(2, k));
    res = add(res, 1);
    cout << res;
    return 0;
}