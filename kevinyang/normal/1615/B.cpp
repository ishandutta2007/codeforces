#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int mxn = 200005;
    vector<vector<int>>arr(mxn,vector<int>(20));
    for(int i = 1; i<mxn; i++){
        for(int j = 0; j<20; j++){
            if((1<<j)&i){
                arr[i][j]++;
            }
            arr[i][j]+=arr[i-1][j];
        }
    }
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        int ans = 0;
        for(int i = 0; i<20; i++){
            ans = max(ans,arr[b][i]-arr[a-1][i]);
        }
        cout << b-a+1-ans << "\n";
    }
    return 0;
}