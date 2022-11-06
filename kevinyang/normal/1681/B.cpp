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
        int m;
        cin >> m;
        for(int i = 1; i<=m; i++){
            int x;
            cin >> x;
            sum+=x;
        }
        sum%=n;
        sum++;
        cout << arr[sum] << "\n";
    }
    return 0;
}