#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int fr[2005];
int unused[2005];
ll dp[2005][2005];

const int MOD = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int cn;
    cin >> cn;
    for(int i=1; i<=cn; i++) unused[i] = 1;
    for(int i=1; i<=cn; i++){
        int x;
        cin >> x;
        if(x == -1) fr[i] = 1;
        else{
            unused[x] = 0;
        }
    }
    int n=0, k=0;
    for(int i=1; i<=cn; i++){
        if(unused[i]){
            if(fr[i]) k++;
            else n++;
        }
    }
    dp[0][0] = 1;
    for(int i=1; i<=n+k; i++){
        dp[i][0] = (dp[i-1][0]*i)%MOD;
        dp[i][1] = (dp[i][0]*i)%MOD;
    }
    for(int j=2; j<=k; j++){
        for(int i=0; i<=n+k; i++){
            dp[i][j] = (dp[i][j-1]*i+dp[i+1][j-2]*(j-1))%MOD;
        }
    }
    cout << dp[n][k];
    return 0;
}