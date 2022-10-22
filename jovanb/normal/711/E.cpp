#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000003;

int mul(int a, int b){
    return ((ll)a*b)%MOD;
}

int add(int a, int b){
    return (a+b)%MOD;
}

int sub(int a, int b){
    return add(a, MOD-b);
}

int pw(int a, ll b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int inv(int a){
    a %= MOD;
    return pw(a, MOD-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ll n, k;
    cin >> n >> k;
    if(n < 63 && (1LL<<n) < k){
        cout << "1 1";
        return 0;
    }
    int p = 1;
    ll ukup = 0;
    ll tren = 2;
    while(tren <= k-1){
        ukup += (k-1)/tren;
        tren *= 2;
    }
    if(k > MOD){
        p = 0;
    }
    else{
        int pw2 = pw(2, n);
        for(ll i=1; i<k; i++){
            int x = i;
            int cnt = 0;
            while(x%2 == 0){
                cnt++;
                x /= 2;
            }
            int r = pw2;
            r = sub(r, i);
            r = mul(r, inv(pw(2, cnt)));
            p = mul(p, r);
        }
    }
    int res = pw(pw(2, k-1), n);
    res = mul(res, inv(pw(2, ukup)));
    cout << sub(res, p) << " " << res << "\n";
    return 0;
}