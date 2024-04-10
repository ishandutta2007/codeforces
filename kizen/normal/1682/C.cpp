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
        sort(a.begin(), a.end());
        int ac = 0, bc = 0, f = 1;
        for(int i = 0; i < n; ++i){
            int j = i;
            while(j + 1 < n && a[i] == a[j + 1]){
                ++j;
            }
            if(i == j){
                if(f){
                    ++ac, ++bc;
                    f = 0;
                }
                else{
                    if(ac < bc) ++ac;
                    else ++bc;
                }
            }
            else{
                ++ac, ++bc;
            }
            i = j;
        }
        cout << min(ac, bc) << '\n';
    }
    return 0;
}