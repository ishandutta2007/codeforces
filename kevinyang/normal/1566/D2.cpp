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
        vector<int>arr(n*m+1);
        vector<int>arr2(n*m+1);
        for(int i = 1; i<=n*m; i++){
            cin >> arr[i];
            arr2[i] = arr[i];
        }
        sort(arr2.begin(),arr2.end());
        map<int,int>hm;//prefix row, prefix column, suffix row, suffix column
        for(int i = n*m; i>=1; i--){
            hm[arr2[i]] = i;
        }
        vector<vector<int>>pos(n+1,vector<int>(m+1));
        int ans = 0;
        for(int i = 1; i<=n*m; i++){
            int v = hm[arr[i]];
            int a = (v-1)/m+1;
            int b = (v-1)%m+1;
            for(int j = 1; j<b; j++){
                if(pos[a][j]>0){
                    if(pos[a][j]!=arr[i])ans++;
                }
            }
            pos[a][b] = arr[i];
            hm[arr[i]]++;
        }
        cout << ans << "\n";
    }
    return 0;
}