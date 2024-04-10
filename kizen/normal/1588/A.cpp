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
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i){
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ans = 1;
        for(int i = n - 1; i >= 0; --i){
            if(a[i] == b[i] || a[i] + 1 == b[i]){
                continue;
            }
            ans = 0; break;
        }
        if(ans == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}