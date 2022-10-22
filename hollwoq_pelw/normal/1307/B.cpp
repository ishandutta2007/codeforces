#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x,k,m=-1;
    cin >> n >> x;
    bool t = true;
    for (int i = 0; i < n; i ++){
        cin >> k;
        if (k == x){
            cout << 1 << endl;
            t = false;
        }
        if (k > m){
            m = k;
        }
    }
    if (t){
        if (m > x) cout << 2 << endl;
        else cout << x/m+(x%m>0) << endl;
    }
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}