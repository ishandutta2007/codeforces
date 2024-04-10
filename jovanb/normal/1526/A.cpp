#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[55];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=2*n; i++){
        cin >> a[i];
    }
    sort(a+1, a+1+2*n);
    for(int i=1; i<=n; i++){
        cout << a[i] << " " << a[n+i] << " ";
    }
    cout << "\n";
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