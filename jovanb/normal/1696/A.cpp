#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int res = 0;
    int n, z;
    cin >> n >> z;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        res = max(res, x | z);
    }
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