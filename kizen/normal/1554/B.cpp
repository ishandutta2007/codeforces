#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        int ans = -(int)1e18;
        for(int i = max(0ll, n - 1000ll); i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                uma(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}