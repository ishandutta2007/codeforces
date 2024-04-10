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
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        int cnt = 0;
        for(int i = 2; i<n; i++){
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
                arr[i+1] = max(arr[i],arr[i+2]);
                cnt++;
            }
        }
        cout << cnt << "\n";
        for(int i = 1; i<=n; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}