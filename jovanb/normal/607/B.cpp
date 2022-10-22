#include <bits/stdc++.h>
using namespace std;

int niz[505];
int dp[505][505];

int main(){

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        dp[i][i] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            dp[i][j] = 1000;
        }
    }
    for(int sz=2; sz<=n; sz++){
        for(int l=1; l+sz-1<=n; l++){
            int r = l+sz-1;
            dp[l][r] = min(dp[l][r], dp[l+1][r]+1);
            for(int k=l+2; k<=r; k++){
                if(niz[l] == niz[k]){
                    dp[l][r] = min(dp[l][r], dp[l+1][k-1] + dp[k+1][r]);
                }
            }
            if(niz[l] == niz[l+1]){
                dp[l][r] = min(dp[l][r], dp[l+2][r]+1);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}