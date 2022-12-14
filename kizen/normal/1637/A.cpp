#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(auto&i:a){
            cin >> i;
        }
        int f = 1;
        for(int i = 0; i < n - 1; ++i){
            if(a[i] > a[i + 1]){
                f = 0;
                break;
            }
        }
        cout << (f ? "NO" : "YES") << '\n';
    }
    return 0;
}