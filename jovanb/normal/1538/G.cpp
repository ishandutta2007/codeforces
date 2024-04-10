#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    if(a < b) swap(a, b);
    if(a == b){
        cout << min(x, y)/a << "\n";
        return;
    }
    if(x < y) swap(x, y);
    ll moves = (x-y)/(a-b);
    if(x - moves*a <= 0 || y - moves*b <= 0){
        cout << min(x/a, y/b) << "\n";
        return;
    }
    x -= moves*a;
    y -= moves*b;
    ll dve = y/(a+b);
    moves += 2*dve;
    x -= (a+b)*dve;
    y -= (a+b)*dve;
    if(x >= a && y >= b) moves++;
    cout << moves << "\n";
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