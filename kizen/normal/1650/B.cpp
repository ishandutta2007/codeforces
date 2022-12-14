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
        int l, r, x; cin >> l >> r >> x;
        int p = (r - (x - 1)) / x * x + x - 1;
        while(p > r) p -= x;
        while(p < l) p += x;
        if(l <= p && p <= r){
            cout << p / x + p % x << '\n';
        }
        else{
            cout << r / x + r % x << '\n';
        }
    }
    return 0;
}