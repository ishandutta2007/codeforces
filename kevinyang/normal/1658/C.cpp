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
        vector<int>arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        int mn = 2;
        for(int i = 0; i<n; i++){
            mn = min(mn,arr[i]);
        }
                bool f = true;
        for(int i = 1; i<n; i++){
            if(arr[i]-arr[i-1]>1)f = false;

        }
        if(arr[0]-arr[n-1]>1)f = false;
        sort(arr.begin(),arr.end());

        if(n>1&&arr[1]==1)f = false;
        
        if(f&&mn==1)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}