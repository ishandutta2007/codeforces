#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map <int, int> mp;

void solve(){
    int n, k;
    cin >> n >> k;
    mp.clear();
    bool mz = 0;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(mp[x - k] || mp[x + k]) mz = 1;
        mp[x] = 1;
    }
    if(mz) cout << "Yes\n";
    else cout << "No\n";
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