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
        int ans = (1<<20)-1;
        for(int i = 1; i<=n; i++){
            if(arr[i]!=i-1){
                ans&=arr[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}