#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n, x;
    cin >> n >> x;
    int mn = 0, mx = 0;
    int t = 0;
    for(int i=1; i<=n; i++){
        int k;
        cin >> k;
        if(i == 1){
            mn = mx = k;
            continue;
        }
        mn = min(mn, k);
        mx = max(mx, k);
        if(mx - mn > 2*x){
            mn = mx = k;
            t++;
        }
    }
    cout << t << "\n";
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