#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1000000007;

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

struct broj{
    int p, q;
    broj(int x, int y){
        p = x;
        q = y;
    }
};

int fact[200005];
int invfact[200005];

int choose(int n, int k){
    if(n < k || n < 0) return 0;
    int res = fact[n];
    res = mul(res, invfact[n-k]);
    res = mul(res, invfact[k]);
    return res;
}

void solve(){
    int n, k;
    cin >> n >> k;
    int res = 1;
    for(int turns=1; turns<=n; turns++){
        if((turns-1)*(k-1) > n) break;
        res = add(res, mul(choose(n - (turns-1)*(k-1), turns), pw(choose(n, turns), MOD-2)));
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    fact[0] = 1;
    invfact[0] = 1;
    for(int i=1; i<=200000; i++){
        fact[i] = mul(i, fact[i-1]);
        invfact[i] = pw(fact[i], MOD-2);
    }
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}