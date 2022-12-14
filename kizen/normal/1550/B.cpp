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
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;
        int cnt = 1;
        for(int i = 1; i < n; ++i){
            if(s[i] != s[i - 1]){
                ++cnt;
            }
        }
        int ans = a * n + b * n;
        uma(ans, a * n + (cnt / 2 + 1) * b);
        cout << ans << '\n';
    }
    return 0;
}