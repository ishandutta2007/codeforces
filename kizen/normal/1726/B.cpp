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
        int n, m; cin >> n >> m;

        if(n % 2 == 0){
            if(m >= n && m % 2 == 0){
                cout << "Yes\n";

                for(int i = 0; i + 2 < n; ++i){
                    cout << "1 ";
                }
                cout << m / 2 - (n - 2) / 2 << ' ' << m / 2 - (n - 2) / 2 << '\n';
            }
            else{
                cout << "No\n";
            }
        }
        else{
            if(m >= n){
                cout << "Yes\n";

                for(int i = 0; i + 1 < n; ++i){
                    cout << "1 ";
                }
                cout << m - (n - 1) << '\n';
            }
            else{
                cout << "No\n";
            }
        }
    }
    
    return 0;
}