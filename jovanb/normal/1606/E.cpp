#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 998244353;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a;}
int mul(int a, int b){ return (1LL*a*b)%MOD; }
int sub(int a, int b){ return add(a, MOD - b); }

const int N = 500;

int dp[N+5][N+5];
int bin[N+5][N+5];

int choose(int a, int b){
    return bin[a][b];
}

int step[N+5][N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, x;
    cin >> n >> x;
    for(int i=0; i<=n; i++){
        bin[i][0] = 1;
        if(i) for(int j=1; j<=i; j++){
            bin[i][j] = add(bin[i-1][j], bin[i-1][j-1]);
        }
    }
    for(int i=0; i<=n; i++){
        step[i][0] = 1;
        for(int j=1; j<=n; j++) step[i][j] = mul(step[i][j-1], i);
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<=x; j++){
            if(j <= (i-1)) dp[i][j] = sub(step[j][i], step[j-1][i]);
            else for(int k=0; k+1<i; k++){
                dp[i][j] = add(dp[i][j], mul(mul(choose(i, k), step[i-1][k]), dp[i-k][j - (i-1)]));
            }
        }
    }
    int res = 0;
    for(int i=1; i<=x; i++) res = add(res, dp[n][i]);
    cout << res << "\n";
    return 0;
}