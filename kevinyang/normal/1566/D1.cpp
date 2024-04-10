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
        vector<int>arr(m+1);
        vector<int>arr2(m+1);
        for(int i = 1; i<=m; i++){
            cin >> arr[i];
            arr2[i] = arr[i];
        }
        sort(arr2.begin(),arr2.end());
        map<int,int>hm;
        for(int i = 1; i<=m; i++){
            hm[arr2[i]] = i;
        }
        int ans = 0;
        vector<int>pos(m+1);
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<hm[arr[i]]; j++){
                if(pos[j])ans++;    
            }
            pos[hm[arr[i]]] = 1;
            hm[arr[i]]--;
        }
        cout << ans << "\n";
    }
    return 0;
}