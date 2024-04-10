#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

ll a[N+5];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    ll res = 1LL*n*(n-1) - k*(a[n] | a[n-1]);
    for(int i=n; i>=1; i--){
        for(int j=i-1; 1LL*i*j >= res && j >= 1; j--){
            res = max(res, 1LL*i*j - k*(a[i] | a[j]));
        }
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