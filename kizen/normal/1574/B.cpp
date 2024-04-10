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
        vector<int> a(3);
        int m;
        cin >> a[0] >> a[1] >> a[2] >> m;
        sort(a.begin(), a.end());
        int low, high;
        low = max(0ll, a[2] - a[0] - a[1] - 1);
        high = a[0] + a[1] + a[2] - 3;
        if(m >= low && m <= high) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}