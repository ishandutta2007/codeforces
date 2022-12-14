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
        while(n < 6) ++n;
        if(n % 2) ++n;
        int val = n - (n % 10);
        if(val == n) val -= 10;
        val -= 10;
        cout << val / 10 * 25 + (n - val) * 5 / 2 << '\n';
    }
    return 0;
}