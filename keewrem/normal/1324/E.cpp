#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001];
bool p[2001][2001];
int main(){
    int n,h,l,r;
    cin >> n >> h >> l >> r;
    int a[n];
    for(int i = 0; i < n; i++)cin >> a[i];
    p[0][0]=1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < h; j++)if(p[i][j]){
            p[i+1][(j+a[i])%h]=1; p[i+1][(j+a[i]-1)%h]=1;
            dp[i+1][(j+a[i])%h]=max(dp[i+1][(j+a[i])%h],dp[i][j]+((j+a[i])%h<=r && (j+a[i])%h>=l));
            dp[i+1][(j+a[i]-1)%h]=max(dp[i+1][(j+a[i]-1)%h],dp[i][j]+((j+a[i]-1)%h<=r && (j+a[i]-1)%h>=l));
        }
    }
    int m =0;
    for(int i = 0; i < h; i++)m = max(m,dp[n][i]);
    cout << m << endl;
    return 0;
}