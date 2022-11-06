#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i = 0; i<n; i+=2){
            for(int j = 0; j<m; j+=2){
                if((i+j)%4==0){
                    ans[i][j] = 1; ans[i+1][j+1] = 1;
                }
                else{
                    ans[i+1][j] = 1; ans[i][j+1] = 1;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}