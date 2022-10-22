#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    cin >> n;
    ll sum = 0;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        sum += x;
    }
    ll ost = sum%n;
    cout << ost*(n-ost) << "\n";
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