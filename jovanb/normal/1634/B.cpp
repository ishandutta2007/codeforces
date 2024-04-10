#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    ll x, y;
    cin >> n >> x >> y;
    y %= 2;
    x %= 2;
    ll pr = 0;
    for(int i=1; i<=n; i++){
        ll g;
        cin >> g;
        pr = (pr + g)%2;
    }
    if((x + pr)%2 == y%2) cout << "Alice\n";
    else cout << "Bob\n";
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