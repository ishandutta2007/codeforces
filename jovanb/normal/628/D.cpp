#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int dp[2005][2005][2][2];

const int MOD = 1000000007;

int add(int a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int m, d;
    cin >> m >> d;
    string a, b;
    cin >> a >> b;
    int n = a.size();
    dp[0][0][1][1] = 1;
    for(int i=0; i<n; i++){
        for(int pmod=0; pmod<m; pmod++){
            int l = 0, r = 9;
            if(i%2 == 1) l = r = d;
            for(int e=l; e<=r; e++){
                if(e == d && l < r) continue;
                /// 0, 0
                dp[i+1][(10*pmod+e)%m][0][0] = add(dp[i+1][(10*pmod+e)%m][0][0], dp[i][pmod][0][0]);
                /// 0, 1
                if(e < b[i] - '0') dp[i+1][(10*pmod+e)%m][0][0] = add(dp[i+1][(10*pmod+e)%m][0][0], dp[i][pmod][0][1]);
                if(e == b[i] - '0') dp[i+1][(10*pmod+e)%m][0][1] = add(dp[i+1][(10*pmod+e)%m][0][1], dp[i][pmod][0][1]);
                /// 1, 0
                if(e > a[i] - '0') dp[i+1][(10*pmod+e)%m][0][0] = add(dp[i+1][(10*pmod+e)%m][0][0], dp[i][pmod][1][0]);
                if(e == a[i] - '0') dp[i+1][(10*pmod+e)%m][1][0] = add(dp[i+1][(10*pmod+e)%m][1][0], dp[i][pmod][1][0]);
                /// 1, 1
                if(e == a[i] - '0' && e == b[i] - '0') dp[i+1][(10*pmod+e)%m][1][1] = add(dp[i+1][(10*pmod+e)%m][1][1], dp[i][pmod][1][1]);
                if(e == a[i] - '0' && e < b[i] - '0') dp[i+1][(10*pmod+e)%m][1][0] = add(dp[i+1][(10*pmod+e)%m][1][0], dp[i][pmod][1][1]);
                if(e > a[i] - '0' && e == b[i] - '0') dp[i+1][(10*pmod+e)%m][0][1] = add(dp[i+1][(10*pmod+e)%m][0][1], dp[i][pmod][1][1]);
                if(e > a[i] - '0' && e < b[i] - '0') dp[i+1][(10*pmod+e)%m][0][0] = add(dp[i+1][(10*pmod+e)%m][0][0], dp[i][pmod][1][1]);
            }
        }
    }
    cout << add(add(add(dp[n][0][0][0], dp[n][0][0][1]), dp[n][0][1][0]), dp[n][0][1][1]) << "\n";
    return 0;
}