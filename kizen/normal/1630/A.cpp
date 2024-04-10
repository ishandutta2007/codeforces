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
        int n, k;
        cin >> n >> k;
        if(!k){
            for(int i = 0; i < n / 2; ++i){
                cout << i << ' ' << ((n - 1) ^ i) << '\n';
            }
        }
        else if(k != n - 1){
            for(int i = 1; i < n / 2; ++i){
                if(i != k && ((n - 1) ^ i) != k){
                    cout << i << ' ' << ((n - 1) ^ i) << '\n';
                }
            }
            cout << 0 << ' ' << ((n - 1) ^ k) << '\n';
            cout << k << ' ' << n - 1 << '\n';
        }
        else{
            if(n <= 4){
                cout << "-1\n";
            }
            else{
                cout << n - 2 << ' ' << n - 1 << '\n';
                for(int i = 2; i < n / 2; ++i){
                    if(i == 3){
                        continue;
                    }
                    cout << i << ' ' << ((n - 1) ^ i) << '\n';
                }
                cout << 1 << ' ' << 3 << '\n';
                cout << 0 << ' ' << ((n - 1) ^ 3) << '\n';
            }
        }
    }
    return 0;
}