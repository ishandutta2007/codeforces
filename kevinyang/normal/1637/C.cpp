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
        if(n==3){
            if(arr[2]%2==0){
                cout << arr[2]/2 << "\n";
            }
            else{
                cout << "-1\n";
            }
            continue;
        }
        bool f = true;
        for(int i = 2; i<n; i++){
            if(arr[i]>1){
                f = false;
            }
        }
        if(f){
            cout << "-1\n";
            continue;
        }
        int ans = 0;
        for(int i = 2; i<n; i++){
            ans+=(arr[i]+1)/2;
        }
        cout << ans << "\n";
    }
    return 0;
}