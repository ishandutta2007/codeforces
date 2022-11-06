#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        int cnt = 0;
        vector<bool>vis(n+1);
        for(int i = n; i>=1; i--){
            if(vis[arr[i]])break;
            vis[arr[i]] = true;
            cnt++;
        }
        cout << n-cnt << "\n";
    }
    return 0;
}