#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll niz[1000005];
ll res[1000005];
ll pow2[1000005];

const ll MOD = 998244353;

ll mul(ll a, ll b){
    a %= MOD;
    b %= MOD;
    return (a*b)%MOD;
}

ll add(ll a, ll b){
    a %= MOD;
    b %= MOD;
    return (a+b)%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll n;
    cin >> n;
    pow2[0] = 1;
    res[0] = 1;
    for(ll i=1; i<=n+5; i++){
        pow2[i] = mul(2, pow2[i-1]);
        res[i] = mul(pow2[i-1], i+2);
    }
    ll rez = 0;
    for(ll i=1; i<=n; i++){
        cin >> niz[i];
        rez = add(rez, mul(niz[i], res[n-i]));
    }
    cout << rez;
    return 0;
}