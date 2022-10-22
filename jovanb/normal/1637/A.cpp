#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    cin >> n;
    int lst = 0, mz = 0;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x < lst) mz = 1;
        lst = x;
    }
    if(mz) cout << "YES\n";
    else cout << "NO\n";
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