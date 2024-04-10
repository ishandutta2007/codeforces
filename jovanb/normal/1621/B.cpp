#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    cin >> n;
    int L = 1e9, R = 0;
    int cl = 1e9, cr = 1e9, cc = 2e9;
    for(int i=1; i<=n; i++){
        int l, r, x;
        cin >> l >> r >> x;
        if(L > l){
            L = l;
            cl = x;
            cc = 2e9;
        }
        if(R < r){
            R = r;
            cr = x;
            cc = 2e9;
        }
        R = max(R, r);
        if(L == l) cl = min(cl, x);
        if(R == r) cr = min(cr, x);
        if(l == L && r == R) cc = min(cc, x);
        cout << min(cl + cr, cc) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}