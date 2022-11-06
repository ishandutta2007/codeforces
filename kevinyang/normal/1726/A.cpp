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
        
        vector<int>a(n);
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        if(n==1){
            cout << "0\n";
            continue;
        }
        int ans = 0;
        int minl = 1e9; int maxr = 0;
        for(int i = 0; i<n-1; i++){
            minl = min(minl,a[i]);
        }
        for(int i = 1; i<n; i++){
            maxr=  max(maxr,a[i]);
        }
        ans = max(a[n-1]-minl,maxr-a[0]);
        for(int i = 1; i<n; i++){
            ans = max(ans,a[i-1]-a[i]);
        }
        cout << ans << "\n";
    }
    
    return 0;
}