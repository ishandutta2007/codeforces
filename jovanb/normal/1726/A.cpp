#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[2005];

void solve(){
    int n;
    cin >> n;
    int res = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=2; i<=n; i++) res = max(res, a[i] - a[1]);
    for(int i=1; i<n; i++) res = max(res, a[n] - a[i]);
    for(int i=1; i<n; i++) res = max(res, a[i] - a[i+1]);
    res = max(res, a[n] - a[1]);
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