#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll a[200005];

void solve(){
    int n;
    cin >> n;
    ll sum = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum%n){
        cout << "-1\n";
        return;
    }
    ll cnt = 0;
    for(int i=1; i<=n; i++){
        if(n*a[i] > sum) cnt++;
    }
    cout << cnt << "\n";
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