#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int w,h;
        cin >> w >> h;
        vector<vector<int>>arr(4);
        vector<int>sz(4);
        for(int i = 0; i<4; i++){
            cin >> sz[i];
            for(int j = 0; j<sz[i]; j++){
                int x;
                cin >> x;
                arr[i].push_back(x);
            }
        }
        int ans = (arr[0][sz[0]-1]-arr[0][0])*h;
        ans = max(ans,(arr[1][sz[1]-1]-arr[1][0])*h);
        ans = max(ans,(arr[2][sz[2]-1]-arr[2][0])*w);
        ans = max(ans,(arr[3][sz[3]-1]-arr[3][0])*w);
        cout << ans << "\n";
    }
    return 0;
}