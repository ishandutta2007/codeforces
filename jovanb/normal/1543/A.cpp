#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    ll a, b;
    cin >> a >> b;
    if(a == b){
        cout << "0 0\n";
        return;
    }
    if(a < b) swap(a, b);
    ll nzd = abs(a-b);
    cout << nzd << " " << min(a%nzd, nzd-(a%nzd)) << "\n";
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