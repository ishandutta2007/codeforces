#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>>arr(2*n+1,vector<int>(2*n+1));
        for(int i = 1; i<=2*n; i++){
            for(int j = 1; j<=2*n; j++){
                cin >> arr[i][j];
            }
        }
        int ans = min({arr[n+1][n],arr[n][n+1],arr[n][2*n],arr[2*n][n],arr[1][n+1],arr[1][2*n],arr[n+1][1],arr[2*n][1]});

        for(int i = n+1; i<=2*n; i++){
            for(int j = n+1; j<=2*n; j++){
                ans+=arr[i][j];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}