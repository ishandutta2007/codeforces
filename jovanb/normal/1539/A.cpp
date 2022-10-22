#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    ll n, x, t;
    cin >> n >> x >> t;
    if(x > t){
        cout << "0\n";
        return;
    }
    ll g = t/x;
    if(n < g){
        cout << n*(n-1)/2 << "\n";
        return;
    }
    ll res = g*(g-1)/2;
    n -= g;
    res += n*g;
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