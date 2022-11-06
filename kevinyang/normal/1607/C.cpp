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
        sort(arr.begin()+1,arr.end());
        int cur = 0;
        int ans = -(int)1e18;
        ans = max(ans,arr[1]);
        for(int i = 1; i<=n; i++){
            arr[i]+=cur;
            ans = max(ans,arr[i]);
            cur-=arr[i];
        }
        cout << ans << "\n";
    }
    return 0;
}