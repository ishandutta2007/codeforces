#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
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
        vector<int>idx(n+1);
        for(int i = 1; i<=n; i++){
            idx[arr[i]] = i;
        }
        int ans = 1;
        int l = idx[0]; int r = idx[0];
        for(int i = 1; i<n; i++){
            int ind = idx[i];
            if(ind<l){
                l = ind;
            }
            else if(ind>r){
                r = ind;
            }
            else{
                ans*=(r-l+1-i);
                ans%=mod;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}