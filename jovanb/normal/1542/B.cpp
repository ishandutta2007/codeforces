#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    ll n, a, b;
    cin >> n >> a >> b;
    if(a == 1){
        if((n-1)%b == 0) cout << "Yes\n";
        else cout << "No\n";
        return;
    }
    ll poc = 1;
    while(poc <= n){
        if((n-poc)%b == 0){
            cout << "Yes\n";
            return;
        }
        poc *= a;
    }
    cout << "No\n";
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