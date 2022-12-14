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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        int o = 0, z = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i];

            if(a[i] == 1){
                o = 1;
            }
            if(a[i] == 0){
                z = 1;
            }
        }

        if(!z || o){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}