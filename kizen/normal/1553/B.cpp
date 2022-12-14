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
        string x, y; cin >> x >> y;
        int ans = 0;
        int n = (int)x.size(), m = (int)y.size();
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                if(j - i + 1 > m || x[j] != y[j - i]){
                    break;
                }
                if(j - i + 1 + j >= m){
                    int f = 1;
                    for(int k = j - 1; k >= j - (m - (j - i + 1)); --k){
                        if(x[k] != y[j - k + j - i]){
                            f = 0;
                            break;
                        }
                    }
                    if(f) ans = 1;
                }
                if(ans) break;
            }
            if(ans) break;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}