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
        sort(arr.begin(),arr.end());
        int a = 0; int b = 0;
        for(int i = 0; i<(n+1)/2; i++){
            a+=arr[i];
        }
        reverse(arr.begin(),arr.end());
        for(int i = 0; i<(n-1)/2; i++){
            b+=arr[i];
        }
        if(b>a){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}