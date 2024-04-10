#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007;

ll mul(ll a, ll b){
    b %= MOD;
    a %= MOD;
    return (a*b)%MOD;
}

ll add(ll a, ll b){
    b %= MOD;
    a %= MOD;
    return (a+b)%MOD;
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

    ll x, n;
    cin >> x >> n;
    vector <ll> primes;
    for(ll i=2; i*i<=x; i++){
        if(x%i == 0){
            primes.push_back(i);
            while(x%i == 0) x /= i;
        }
    }
    if(x > 1) primes.push_back(x);
    ll res = 1;
    for(auto c : primes){
        x = c;
        ll tren = 0;
        while(x <= n){
            tren = (tren+n/x)%1000000006;
            if(n/x < c) break;
            x *= c;
        }
        res = mul(res, pw(c, tren));
    }
    cout << res;
    return 0;
}