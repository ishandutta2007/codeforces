#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    ll hc, dc, hm, dm;
    cin >> hc >> dc >> hm >> dm;
    ll k, w, a;
    cin >> k >> w >> a;
    for(int i=0; i<=k; i++){
        if((hm + dc + i*w - 1)/(dc + i*w) <= (hc + (k-i)*a + dm - 1)/dm){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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