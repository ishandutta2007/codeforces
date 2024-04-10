#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    ll l, r;
    cin >> l >> r;
    ll moves = r-l;
    ll res = 0;
    ll dos = 0;
    for(int j=1; j<=r; j*=10){
        ll ostalo = moves - (j - dos);
        if(ostalo < 0){
            dos += j*(l%10);
            l /= 10;
            continue;
        }
        res++;
        res += ostalo/j;
        dos += j*(l%10);
        l /= 10;
    }
    cout << res << "\n";
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