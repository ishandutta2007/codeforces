#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, tp, mn = -1, mx = -1;
        cin >> n >> k;
        while(n--){
            cin >> tp;
            if (mn == -1 || mn > tp) mn = tp;
            if (mx == -1 || mx < tp) mx = tp;
        }
        if (mn + k < mx - k) cout << -1 << endl;
        else cout << mn+k << endl;
    }
    return 0;
}