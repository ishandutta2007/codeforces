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
        vector<int>arr(n+5);
        for(int i = 0; i<n; i++){
            int x,y;
            cin >> x >> y;
            arr[x]++; arr[y+1]--;
        }
        for(int i = 1; i<=n; i++){
            arr[i]+=arr[i-1];
        }
        vector<bool>vis(n+1);
        for(int v = 1; v<=n; v++){
            int idx = 0;
            int mn = (int)1e9;
            for(int i = 1; i<=n; i++){
                if(vis[i])continue;
                if(arr[i]<mn){
                    mn = arr[i]; idx = i;
                    
                }
            }
            int l = idx; int r = idx;
            while(!vis[l-1]&&l>1){
                l--;
            }
            while(!vis[r+1]&&r<n){
                r++;
            }
            cout << l << " " << r << " " << idx << "\n";
            vis[idx] = true;
        }
    }
    return 0;
}