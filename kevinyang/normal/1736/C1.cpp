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
        vector<int>a(n+1);
        for(int i = 1; i<=n; i++){
            cin >> a[i];
        }
        vector<int>tim(n+1,(int)1e9);
        for(int i = 1; i<=n; i++){
            if(i-a[i]>=0){
                tim[i-a[i]] = min(tim[i-a[i]],i);
            }
        }
        int ans = 1;
        int r = n+1;
        for(int i = n-1; i>=1; i--){
            r = min(r,tim[i]);
            ans+=r-i;
        }
        cout << ans << "\n";
    }
    return 0;
}