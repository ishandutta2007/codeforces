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
        string s; cin >> s;
        int ans = 0;
        for(auto&i:s){
            uma(ans, (int)i - '0');
        }
        cout << ans << '\n';
    }
    return 0;
}