#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
        int ans = (int)9e18;
        if(pos < (int)a.size()){
            mi(ans, max(0ll, y - (sum - a[pos])));
        }
        if(pos - 1 >= 0){
            mi(ans, x - a[pos - 1] + max(0ll, y - (sum - a[pos - 1])));
        }
        cout << ans << '\n';
    }
    return 0;
}