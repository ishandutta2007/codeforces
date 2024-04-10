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
        vector<int>arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        int ans = 0;
        for(int i = 2; i<n; i++){
            ans = max(ans,arr[i]-arr[0]+arr[i]-arr[i-1]);
        }
        for(int i = 0; i<n-2; i++){
            ans = max(ans,arr[n-1]-arr[i]+arr[i+1]-arr[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}