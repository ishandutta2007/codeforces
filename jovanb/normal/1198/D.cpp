#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int mat[55][55];
int dp[55][55][55][55];

int getval(int i1, int j1, int i2, int j2){
    //cout << i1 << " " << j1 << " " << i2 << " " << j2 << " daje " << mat[i2][j2] - mat[i2][j1-1] - mat[i1-1][j2] + mat[i1-1][j1-1] << endl;
    return mat[i2][j2] - mat[i1-1][j2] -  mat[i2][j1-1] + mat[i1-1][j1-1];
}

int solve(int i1, int j1, int i2, int j2){
    if(dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];
    if(i2 < i1 || j2 < j1) return dp[i1][j1][i2][j2] = 0;
    if(getval(i1, j1, i2, j2) == 0) return dp[i1][j1][i2][j2] = 0;
    dp[i1][j1][i2][j2] = max(i2-i1+1, j2-j1+1);
    for(int i=i1; i<i2; i++){
        dp[i1][j1][i2][j2] = min(dp[i1][j1][i2][j2], solve(i1, j1, i, j2) + solve(i+1, j1, i2, j2));
    }
    for(int j=j1; j<j2; j++){
        dp[i1][j1][i2][j2] = min(dp[i1][j1][i2][j2], solve(i1, j1, i2, j) + solve(i1, j+1, i2, j2));
    }
    //cout << i1 << " " << j1 << " " << i2 << " " << j2 << " je " << dp[i1][j1][i2][j2] << endl;
    return dp[i1][j1][i2][j2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=n; j++){
            if(s[j-1] == '#') mat[i][j] = 1;
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }
    for(int i1=0; i1<=n; i1++){
        for(int j1=0; j1<=n; j1++){
            for(int i2=0; i2<=n; i2++){
                for(int j2=0; j2<=n; j2++){
                    dp[i1][j1][i2][j2] = -1;
                }
            }
        }
    }
    cout << solve(1, 1, n, n);
    return 0;
}