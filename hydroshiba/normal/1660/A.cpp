#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    lol a, b;
    cin >> a >> b;

    if(a != 0) cout << a + (b * 2) + 1 << '\n';
    else cout << "1\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}