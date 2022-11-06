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
        vector<int>ans(n);
        for(int i = 0; i<n; i++){
            ans[i] = i;
        }
        for(int i = n-1; i>=0; i--){
            if(__builtin_popcount(ans[i])==1){
                reverse(ans.begin(),ans.begin()+i);
                break;
            }
        }
        for(int i = 0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}