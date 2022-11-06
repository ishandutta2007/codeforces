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
        vector<int>arr(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        vector<int>arr2(n+1);
        vector<int>ans(n+1);
        arr2[1] = arr[1];
        for(int i = 2; i<=n; i++){
            int v = arr2[i-1]|arr[i];
            arr2[i] = v;
            v^=arr[i];
            ans[i] = v;
        }
        for(int i = 1; i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}