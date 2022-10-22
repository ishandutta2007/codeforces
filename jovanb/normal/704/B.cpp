#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 5000;

ll dp[MAXN+5][MAXN+5];
int a[MAXN+5];
int b[MAXN+5];
int c[MAXN+5];
int d[MAXN+5];
int x[MAXN+5];

const ll INF = 1000000000000000000LL;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, s, e;
    cin >> n >> s >> e;
    for(int i=1; i<=n; i++) cin >> x[i];
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    for(int i=1; i<=n; i++) cin >> c[i];
    for(int i=1; i<=n; i++) cin >> d[i];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dp[i][j] = INF;
        }
    }
    dp[1][1] = -2*x[1] + d[1] + b[1];
    if(s == 1) dp[1][1] = -x[1] + d[1];
    else if(e == 1) dp[1][1] = -x[1] + b[1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == s){
                dp[i][j+1] = min(dp[i][j+1], dp[i-1][j] - x[i] + d[i]);
                dp[i][j] = min(dp[i][j], dp[i-1][j] + x[i] + c[i]);
            }
            else if(i == e){
                dp[i][j+1] = min(dp[i][j+1], dp[i-1][j] - x[i] + b[i]);
                dp[i][j] = min(dp[i][j], dp[i-1][j] + x[i] + a[i]);
            }
            else{
                if(!(j == 1 && (i > s) && (i > e))) dp[i][j+1] = min(dp[i][j+1], dp[i-1][j] - 2*x[i] + d[i] + b[i]);
                if(j > (i > s)) dp[i][j] = min(dp[i][j], dp[i-1][j] + b[i] + c[i]);
                if(j > (i > e)) dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i] + d[i]);
                dp[i][j-1] = min(dp[i][j-1], dp[i-1][j] + 2*x[i] + c[i] + a[i]);
            }
        }
    }
    cout << dp[n][1] << "\n";
    return 0;
}