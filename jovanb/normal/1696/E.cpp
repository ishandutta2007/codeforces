#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000000;
const int MOD = 1000000007;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }

int fact[N+5], invfact[N+5];

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int choose(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    int res = fact[n];
    res = mul(res, invfact[k]);
    res = mul(res, invfact[n - k]);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    fact[0] = 1;
    for(int i=1; i<=N; i++) fact[i] = mul(fact[i-1], i);
    invfact[N] = pw(fact[N], MOD - 2);
    for(int i=N-1; i>=0; i--) invfact[i] = mul(invfact[i+1], i + 1);
    int n;
    cin >> n;
    int res = 0;
    for(int i=0; i<=n; i++){
        int x;
        cin >> x;
        if(x == 0) continue;
        res = add(res, choose(i + x, i + 1));
    }
    cout << res << "\n";
    return 0;
}