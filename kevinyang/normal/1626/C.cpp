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
        vector<int>h(n+1);
        vector<int>val(n+5,(int)2e9);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        for(int i = 1; i<=n; i++){
            cin >> h[i];
        }
        for(int i = n; i>=1; i--){
            val[i] = min(arr[i]-h[i],val[i+1]);
            h[i] = arr[i]-val[i];
        }
        int ans = 0;
        int cur = 0;
        for(int i = 1; i<=n; i++){
            if(h[i]<=arr[i]-arr[i-1]){
                cur = h[i];
                ans+=h[i]*(h[i]+1)/2;
            }
            else{
                ans-=cur*(cur+1)/2;
                cur+=arr[i]-arr[i-1];
                ans+=cur*(cur+1)/2;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}