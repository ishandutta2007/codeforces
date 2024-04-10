#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll a[200005];

void solve(){
    int n;
    cin >> n;
    int l = 0, r = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(a[i] == n) r = i;
        if(a[i] == 1) l = i;
    }
    if(l > r) swap(l, r);
    cout << min(l+(n-r+1), min(r, n-l+1)) << "\n";
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