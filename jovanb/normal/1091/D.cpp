#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll res;

const int MOD = 998244353;

ll fak[1000005];
ll inverz[1000005];

ll mul(ll a, ll b){
    return (a*b)%MOD;
}

ll add(ll a, ll b){
    return (a+b+MOD)%MOD;
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
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    fak[0] = 1;
    for(int i=1; i<=n; i++){
        fak[i] = mul(fak[i-1], i);
        inverz[i] = pw(fak[i], MOD-2);
    }
    res = fak[n];
    for(int i=1; i<n; i++){
        ll inv = inverz[n-i];
        ll r1 = mul(fak[n], inv);
        ll inv2 = inverz[i];
        ll r2 = mul(r1, inv2);
        r1 = add(r1, -r2);
        r1 = mul(r1, fak[n-i]);
        res = add(r1, res);
    }
    cout << res;
    return 0;
}