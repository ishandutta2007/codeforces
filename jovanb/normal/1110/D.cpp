#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int dp[1000005][3][3];

const int INF = 1000000000;

int ima[1000005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        ima[x]++;
    }
    for(int i=1; i<=m; i++){
        for(int j=0; j<=2; j++){
            for(int k=0; k<=2; k++){
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[1][0][0] = 0;
    for(int i=1; i<=m; i++){
        for(int j=0; j<=2; j++){
            for(int k=0; k<=2; k++){
                for(int l=0; l<=2; l++){
                    if(ima[i] >= j+k+l && ima[i+1] >= k+l && ima[i+2] >= l) dp[i+1][k][l] = max(dp[i+1][k][l], l + (ima[i]-j-k-l)/3 + dp[i][j][k]);
                }
            }
        }
    }
    cout << dp[m+1][0][0] << "\n";
    return 0;
}