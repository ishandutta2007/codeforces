#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    ll a, b;
    cin >> a >> b;
    if(b == 1) cout << "NO\n";
    else{
        cout << "YES\n";
        cout << a << " " << a*b << " " << a*(b+1) << "\n";
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