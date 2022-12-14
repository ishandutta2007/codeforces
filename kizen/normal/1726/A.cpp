#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        int ans = -(int)1e18;

        for(int i = 0, j = n - 1; ; i = (i + 1) % n, j = (j + 1) % n){
            ans = max(ans, a[j] - a[i]);

            if(i == n - 1) break;
        }

        for(int i = 0; i + 1 < n; ++i){
            ans = max(ans, a[n - 1] - a[i]);
        }
        for(int i = 1; i < n; ++i){
            ans = max(ans, a[i] - a[0]);
        }

        cout << ans << '\n';
    }
    
    return 0;
}