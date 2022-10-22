#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;
ll a[N+5];

void solve(){
    int n;
    cin >> n;
    ll res = 0;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<n; i++){
        res = max(res, a[i]*a[i+1]);
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