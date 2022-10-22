#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll dp[1000][5];
ll uzet[5][1000];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    string s;
    cin >> s;
    int n = s.size();
    for(int i=1; i<=n; i++){
        if(s[i-1] == 'X') uzet[1][i] = 1;
    }
    cin >> s;
    for(int i=1; i<=n; i++){
        if(s[i-1] == 'X') uzet[2][i] = 1;
    }
    if(n == 1){cout << 0; return 0;}
    if(n == 2){
        int pomocza2 = uzet[1][2]+uzet[1][1]+uzet[2][1]+uzet[2][2];
        if(pomocza2 <= 1) cout << 1;
        else cout << 0;
        return 0;
    }
    if(!uzet[1][1] && !uzet[1][2] && !uzet[2][1]) dp[2][1] = 1;
    if(!uzet[1][1] && !uzet[1][2] && !uzet[2][2]) dp[2][2] = 1;
    if(!uzet[2][2] && !uzet[1][2] && !uzet[2][1]) dp[2][3] = 1;
    if(!uzet[1][1] && !uzet[2][2] && !uzet[2][1]) dp[2][4] = 1;
    for(int i=3; i<=n; i++){
        /// prvi
        if(!uzet[1][i-1] && !uzet[1][i] && !uzet[2][i-1]){
            ll trenres = 0;
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][1]);
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][2]);
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][3]);
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][4]);
            dp[i][1] = max(dp[i][1], trenres+1);
        }
        /// drugi
        if(!uzet[1][i-1] && !uzet[1][i] && !uzet[2][i]){
            ll trenres = 0;
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][1]);
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][2]);
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][3]);
            for(int j=i-1; j>=1; j--) trenres = max(trenres, dp[j][4]);
            dp[i][2] = max(dp[i][2], trenres+1);
        }
        /// treci
        if(!uzet[2][i] && !uzet[1][i] && !uzet[2][i-1]){
            ll trenres = 0;
            for(int j=i-1; j>=1; j--) trenres = max(trenres, dp[j][1]);
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][2]);
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][3]);
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][4]);
            dp[i][3] = max(dp[i][3], trenres+1);
        }
        /// cetvrti
        if(!uzet[1][i-1] && !uzet[2][i] && !uzet[2][i-1]){
            ll trenres = 0;
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][1]);
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][2]);
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][3]);
            for(int j=i-2; j>=1; j--) trenres = max(trenres, dp[j][4]);
            dp[i][4] = max(dp[i][4], trenres+1);
        }
    }
    ll maxi=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=4; j++){
            maxi = max(maxi, dp[i][j]);
        }
    }
    cout << maxi;
    return 0;
}