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
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 0; i + 1 < n; ++i){
            uma(ans, a[i] * a[i + 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}