#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    cin >> n;
    int x = 0;
    for(int j=0; j<30; j++){
        if((1 << j) & (n-1)) x = (1 << j);
    }
    for(int i=x-1; i>=0; i--) cout << i << " ";
    for(int i=x; i<n; i++) cout << i << " ";
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