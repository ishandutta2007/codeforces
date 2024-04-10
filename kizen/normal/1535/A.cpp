#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        vector<int> a(4);
        for(int i = 0; i < 4; ++i){
            cin >> a[i];
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        if((a[0] == b[3] || a[0] == b[2] || a[1] == b[3] || a[1] == b[2]) && 
            (a[2] == b[3] || a[2] == b[2] || a[3] == b[3] || a[3] == b[2])){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}