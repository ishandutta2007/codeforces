#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    ll a, b;
    cin >> a >> b;
    if(a == 0 && b == 0){
        cout << "0\n";
        return;
    }
    if(a == b){
        cout << "1\n";
        return;
    }
    if(a%2 != b%2) cout << "-1\n";
    else cout << "2\n";
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