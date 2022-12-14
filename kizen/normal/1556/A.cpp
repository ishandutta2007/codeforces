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
        int a, b; cin >> a >> b;
        if((a + b) % 2){
            cout << "-1\n";
        }
        else if(a == 0 && b == 0) cout << "0\n";
        else if(a == b) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}