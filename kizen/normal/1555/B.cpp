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
        int w, h; cin >> w >> h;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int a, b; cin >> a >> b;
        int ans = (int)1e18;
        if(a <= max(x1, w - x2) || b <= max(y1, h - y2)) ans = 0;
        if(a + x2 - x1 <= w){
            ans = min(ans, abs(a - x1));
            ans = min(ans, abs(w - a - x2));
        }
        if(b + y2 - y1 <= h){
            ans = min(ans, abs(b - y1));
            ans = min(ans, abs(h - b - y2));
        }
        if(a + x2 - x1 > w && b + y2 - y1 > h) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}