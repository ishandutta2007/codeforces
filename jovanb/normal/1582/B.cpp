#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    cin >> n;
    ll res = 1, one = 0, zero = 0;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x == 0) res *= 2, zero++;
        else if(x == 1) one++;
    }
    cout << one*res << "\n";
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