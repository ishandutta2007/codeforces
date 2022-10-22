#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1000000007;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }
int sub(int a, int b){ return add(a, MOD - b); }

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

const int N = 1000000;

int dp[3*N+5][3];
int fact[3*N+5];
int invfact[3*N+5];

int choose(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    return mul(mul(fact[n], invfact[n-k]), invfact[k]);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, qrs;
    cin >> n >> qrs;
    fact[0] = 1;
    for(int i=1; i<=3*n+1; i++) fact[i] = mul(i, fact[i-1]);
    invfact[3*n+1] = pw(fact[3*n+1], MOD - 2);
    for(int i=3*n; i>=0; i--) invfact[i] = mul(invfact[i+1], i+1);
    int inv3 = pw(3, MOD - 2);
    dp[0][0] = dp[0][1] = dp[0][2] = n;
    for(int i=1; i<=3*n; i++){
        dp[i][0] = mul(sub(sub(choose(3*n, i + 1), mul(2, dp[i-1][0])), dp[i-1][1]), inv3);
        dp[i][1] = add(dp[i-1][0], dp[i][0]);
        dp[i][2] = add(dp[i-1][1], dp[i][1]);
    }
    while(qrs--){
        int x;
        cin >> x;
        cout << add(dp[x][0], choose(3*n, x)) << "\n";
    }
    return 0;
}