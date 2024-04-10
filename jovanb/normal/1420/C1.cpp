#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[300005];

ll uradi(int i){
    if(a[i-1] < a[i] && a[i] > a[i+1]) return a[i];
    if(a[i-1] > a[i] && a[i] < a[i+1]) return -a[i];
    return 0;
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    a[0] = a[n+1] = -1;
    ll sum = 0;
    for(int i=1; i<=n; i++){
        sum += uradi(i);
    }
    cout << sum << "\n";
    while(q--){
        int i, j;
        cin >> i >> j;
        if(i > j) swap(i, j);
        if(i > 1) sum -= uradi(i-1);
        sum -= uradi(i);
        if(i+1 <= n) sum -= uradi(i+1);
        if(j-1 > i+1) sum -= uradi(j-1);
        if(j > i+1) sum -= uradi(j);
        if(j+1 <= n) sum -= uradi(j+1);
        swap(a[i], a[j]);
        if(i > 1) sum += uradi(i-1);
        sum += uradi(i);
        if(i+1 <= n) sum += uradi(i+1);
        if(j-1 > i+1) sum += uradi(j-1);
        if(j > i+1) sum += uradi(j);
        if(j+1 <= n) sum += uradi(j+1);
        cout << sum << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}