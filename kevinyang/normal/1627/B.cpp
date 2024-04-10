#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        if(n>m){
            swap(n,m);
        }
        vector<vector<int>>arr(n+1,vector<int>(m+1,(int)1e9));
        vector<int>sorted;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                arr[i][j] = max({i-1+j-1,n-i+j-1,i-1+m-j,n-i+m-j});
                sorted.push_back(arr[i][j]);
            }
        }
        sort(sorted.begin(),sorted.end());
        for(int nxt: sorted){
            cout << nxt << " ";
        }
        cout << "\n";
    }
    return 0;
}