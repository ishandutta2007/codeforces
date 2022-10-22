#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;
int fact[505];
int dp[505][505];
int pwk[1005];
int pwk1[1005];
int inv[1005];

int add(int a, int b){
    return (a+b)%MOD;
}

int mul(int a, int b){
    return ((ll)a*b)%MOD;
}

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}


int bin(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    int res = fact[n];
    res = mul(res, inv[k]);
    res = mul(res, inv[n-k]);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    fact[0] = 1;
    inv[0] = 1;
    for(int i=1; i<=500; i++){
        fact[i] = mul(i, fact[i-1]);
        inv[i] = pw(fact[i], MOD-2);
    }
    pwk[0] = 1;
    for(int i=1; i<=1000; i++) pwk[i] = mul(pwk[i-1], k);
    pwk1[0] = 1;
    for(int i=1; i<=1000; i++) pwk1[i] = mul(pwk1[i-1], k-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            for(int l=0; l<=n-j; l++){
                int jos = pwk[j];
                jos = mul(jos, pwk1[n-j-l]);
                jos = mul(jos, bin(n-j, l));
                if(l == 0){
                    jos = add(jos, MOD - pwk1[n]);
                }
                jos = mul(jos, dp[i][j]);
                dp[i+1][j+l] = add(dp[i+1][j+l], jos);
            }
        }
    }
    cout << dp[n][n];
    return 0;
}