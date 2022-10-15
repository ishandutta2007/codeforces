#include "bits/stdc++.h"
using namespace std;

void solve(){
    long long u, v;
    cin >> u >> v;

    long long c = v * v;
    long long d = u * u;

    cout << -d << ' ' << c << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}