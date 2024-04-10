#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

int mul(int a, int b){
    ll k = (ll)a*b;
    if(k < MOD) return k;
    return k%MOD;
}

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int inv(int n){
    return pw(n, MOD-2);
}

int fact(int n){
    int res = 1;
    for(int i=2; i<=n; i++) res = mul(res, i);
    return res;
}

int bin(int n, int k){
    if(n < k || n < 0 || k < 0) return 0;
    int res = fact(n);
    res = mul(res, inv(fact(k)));
    res = mul(res, inv(fact(n-k)));
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m, k;
    cin >> n >> m >> k;
    cout << mul(bin(n-1, 2*k), bin(m-1, 2*k));
    return 0;
}