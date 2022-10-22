#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int MOD;

int add(int a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int sub(int a, int b){
    return add(a, MOD-b);
}

int dp[2][250005];
int pref[2][250005];
int factpos[505];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n >> MOD;
    int res = 0;
    factpos[0] = 1;
    for(int i=n; i>=1; i--){
        factpos[n-i+1] = mul(factpos[n-i], i);
    }
    dp[0][0] = 1;
    pref[0][0] = 1;
    for(int j=1; j<=n*n; j++) pref[0][j] = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<=n*n; j++){
            dp[1][j] = pref[0][j];
            if(j >= i) dp[1][j] = sub(dp[1][j], pref[0][j-i]);
            pref[1][j] = dp[1][j];
            if(j > 0) pref[1][j] = add(pref[1][j], pref[1][j-1]);
        }
        int dele = n - i - 1;
        int sum = 0;
        int sumaovih = 0;
        int sve = 0;

        for(int k=0; k<=i*i; k++){
            sve = sub(sve, sumaovih);
            if(k-i-2 >= 0) sumaovih = sub(sumaovih, pref[1][k-i-2]);
            if(k >= 2) sumaovih = add(sumaovih, pref[1][k-2]);
            if(k >= 2) sve = add(sve, mul(i, pref[1][k-2]));
            sum = add(sum, mul(sve, dp[1][k]));
        }
        for(int k=0; k<=n*n; k++){
            dp[0][k] = dp[1][k];
            dp[1][k] = 0;
            pref[0][k] = pref[1][k];
            pref[1][k] = 0;
        }
        sum = mul(sum, factpos[dele]);
        res = add(res, sum);
    }
    cout << res%MOD << "\n";
    return 0;
}