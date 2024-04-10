#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 998244353;

int add(int a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int fact[200005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    if(n == 2){
        cout << 0;
        return 0;
    }
    fact[0] = 1;
    for(int i=1; i<=m; i++){
        fact[i] = mul(fact[i-1], i);
    }
    int res = fact[m];
    res = mul(res, pw(fact[n-1], MOD-2));
    res = mul(res, pw(fact[m-n+1], MOD-2));
    res = mul(res, n-2);
    res = mul(res, pw(2, n-3));
    cout << res;
    return 0;
}