#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp1[1005][1005];
ll dp2[1005][1005];
ll dp3[1005][1005];
ll dp4[1005][1005];
ll mat[1005][1005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cin >> mat[i][j];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp1[i][j] = mat[i][j]+max(dp1[i-1][j], dp1[i][j-1]);
        }
    }
    for(int i=n; i>0; i--){
        for(int j=1; j<=m; j++){
            dp2[i][j] = mat[i][j]+max(dp2[i+1][j], dp2[i][j-1]);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=m; j>0; j--){
            dp3[i][j] = mat[i][j]+max(dp3[i-1][j], dp3[i][j+1]);
        }
    }
    for(int i=n; i>0; i--){
        for(int j=m; j>0; j--){
            dp4[i][j] = mat[i][j]+max(dp4[i+1][j], dp4[i][j+1]);
        }
    }
    ll maxval = 0;
    for(int i=2; i<n; i++){
        for(int j=2; j<m; j++){
            maxval = max(maxval, dp1[i][j-1]+dp2[i+1][j]+dp3[i-1][j]+dp4[i][j+1]);
            maxval = max(maxval, dp1[i-1][j]+dp2[i][j-1]+dp3[i][j+1]+dp4[i+1][j]);
        }
    }
    cout << maxval;
    return 0;
}