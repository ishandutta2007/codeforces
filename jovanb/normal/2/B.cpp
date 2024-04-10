#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int dp[1005][1005][2];

int n;

void bektrek(int x){
    cout << dp[n][n][x] << "\n";
    int i = n, j = n;
    stack <char> stek;
    while(i > 1 || j > 1){
        if(i == 1){
            stek.push('R');
            j--;
        }
        else if(j == 1){
            stek.push('D');
            i--;
        }
        else if(dp[i-1][j][x] < dp[i][j-1][x]){
            stek.push('D');
            i--;
        }
        else{
            stek.push('R');
            j--;
        }
    }
    while(!stek.empty()){
        cout << stek.top();
        stek.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    int pi = 0, pj = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin >> x;
            int br2 = 0, br5 = 0;
            if(x == 0){
                x = 10;
                pi = i, pj = j;
            }
            while(x%2 == 0){
                br2++;
                x /= 2;
            }
            while(x%5 == 0){
                br5++;
                x /= 5;
            }
            if(i == 1){
                dp[i][j][0] = br2 + dp[i][j-1][0];
                dp[i][j][1] = br5 + dp[i][j-1][1];
            }
            else if(j == 1){
                dp[i][j][0] = br2 + dp[i-1][j][0];
                dp[i][j][1] = br5 + dp[i-1][j][1];
            }
            else{
                dp[i][j][0] = br2 + min(dp[i-1][j][0], dp[i][j-1][0]);
                dp[i][j][1] = br5 + min(dp[i-1][j][1], dp[i][j-1][1]);
            }
        }
    }
    if(min(dp[n][n][0], dp[n][n][1]) > 1 && pi){
        cout << "1\n";
        int ti = 1, tj = 1;
        while(ti < pi){
            ti++;
            cout << "D";
        }
        while(tj < pj){
            tj++;
            cout << "R";
        }
        while(ti < n){
            ti++;
            cout << "D";
        }
        while(tj < n){
            tj++;
            cout << "R";
        }
        return 0;
    }
    if(dp[n][n][0] < dp[n][n][1]) bektrek(0);
    else bektrek(1);
    return 0;
}