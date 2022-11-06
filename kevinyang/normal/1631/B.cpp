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
        int cnt = 0;
        while(true){
            int idx = 0;
            for(int i = n-1; i>=0; i--){
                if(arr[i]!=arr[i+1]){
                    idx = i+1;
                    break;
                }
            }
            if(idx==1)break;
            cnt++;
            int len = n-idx+1;
            for(int i = 1; i<=len; i++){
                if(idx-i==0)break;
                arr[idx-i] = arr[n];
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}