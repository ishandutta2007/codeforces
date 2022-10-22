#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 998244353;

const int N = 300000;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int fact[N+5], invfact[N+5];

int choose(int n, int k){
    if(n < k || n < 0 || k < 0) return 0;
    int res = fact[n];
    res = mul(res, invfact[k]);
    res = mul(res, invfact[n - k]);
    return res;
}

int dp[N+5];
int fact2[N+5];

void solve(){
    int n;
    cin >> n;
    int res = 0;
    for(int k=0; k<=n/2; k+=2){
        int ov = choose(n - k, k);
        ov = mul(ov, pw(2, k/2));
        if(k > 0) ov = mul(ov, fact2[k-1]);
        ov = mul(ov, dp[n - 2*k]);
        res = add(res, ov);
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    fact[0] = 1;
    for(int i=1; i<=N; i++) fact[i] = mul(i, fact[i-1]);
    invfact[N] = pw(fact[N], MOD - 2);
    for(int i=N-1; i>=0; i--) invfact[i] = mul(invfact[i+1], i + 1);

    dp[0] = dp[1] = 1;
    for(int i=2; i<=N; i++){
        dp[i] = add(dp[i], dp[i-1]);
        dp[i] = add(dp[i], mul(i - 1, dp[i-2]));
    }
    fact2[0] = 1;
    fact2[1] = 1;
    for(int i=2; i<=N; i++) fact2[i] = mul(i, fact2[i-2]);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/*
1
1
*/