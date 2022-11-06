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
        vector<int>ans(n+1);
        vector<bool>vis(n+1);
        for(int i = 1; i<=n; i++){
            if(vis[i])continue;
            vector<int>arr;
            while(true){
                cout << "? " << i << endl;
                int v;
                cin >> v;
                if(vis[v])break;
                vis[v] = true;
                arr.push_back(v);
            }
            if(arr.size()==1){
                ans[arr[0]] = arr[0];
            }
            else{
                for(int j = 1; j<arr.size(); j++){
                    ans[arr[j-1]] = arr[j];
                }
                ans[arr[arr.size()-1]] = arr[0];
            }
        }
        cout << "! ";
        for(int i = 1; i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}