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

        int l = 0, r = n - 1, ans = 0;
        while(l <= r){
            while(l <= r && a[l] == 0){
                ++l;
            }
            while(l <= r && a[r] == 1){
                --r;
            }

            if(l <= r){
                ++ans;
                swap(a[l], a[r]);
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}