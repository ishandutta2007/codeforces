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
        if(n<=2){
            cout << "0\n";
            continue;
        }
        int ans = n;
        for(int i = 1; i<=n; i++){
            for(int j = i+1; j<=n; j++){
                int cnt = 2;
                for(int k = 1; k<=n; k++){
                    if(k==i||k==j)continue;
                    if((arr[j]-arr[i])*(k-i)==(arr[k]-arr[i])*(j-i))cnt++;
                }
                ans = min(ans,n-cnt);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}