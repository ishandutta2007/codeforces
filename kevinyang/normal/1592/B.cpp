#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        vector<int>arr(n+1);
        vector<int>arr2(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
            arr2[i] = arr[i];
        }
        bool f = true;
        sort(arr2.begin(),arr2.end());
        for(int i = 1; i<=n; i++){
            if(i<=x&&i+x>n){
                if(arr2[i]!=arr[i])f = false;
            }
        }
        if(f)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}