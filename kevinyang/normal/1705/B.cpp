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
        int sum = 0;
        for(int i = 1; i<n; i++){
            sum+=arr[i];
        }
        if(sum==0){
            cout << "0\n";
            continue;
        }
        int cur = 0;
        for(int i = 1; i<n; i++){
            if(arr[i]==0&&cur>0)sum++;
            cur+=arr[i];
        }
        cout << sum << "\n";
    }
    return 0;
}