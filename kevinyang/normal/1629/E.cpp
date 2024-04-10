#include <bits/stdc++.h>
using namespace std;
#define int long long
bool good(int x, int y, int n){
    if(x>=1&&x<=n&&y>=1&&y<=n)return true;
    return false;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>>arr(n+1,vector<int>(n+1));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                cin >> arr[i][j];
            }
        }
        vector<vector<int>>a(n+1,vector<int>(n+1));
        int ans = 0;
        for(int i = 1; i<n; i++){
            for(int j = 1; j<=n; j++){
                if(a[i][j]==0){
                    int x = i+1; int y = j;
                    if(good(x,y+1,n))a[x][y+1]^=1;
                    if(good(x+1,y,n))a[x+1][y]^=1;
                    if(good(x,y-1,n))a[x][y-1]^=1;
                    if(good(x-1,y,n))a[x-1][y]^=1;
                    ans^=arr[x][y];
                }
            }
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                assert(a[i][j]==1);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}