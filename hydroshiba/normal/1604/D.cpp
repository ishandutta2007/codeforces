
#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    long long x, y;
    cin >> x >> y;
    
    if(x > y) cout << x + y << '\n';
    else cout << y - (y % x) / 2 << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}