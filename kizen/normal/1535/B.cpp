#include <bits/stdc++.h>
#define int long long
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
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                if(a[i] % 2 != a[j] % 2) ++ans;
                else if(a[i] % 2 == 0 || __gcd(a[i], a[j]) > 1) ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}