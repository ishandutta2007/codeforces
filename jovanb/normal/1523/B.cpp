#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
    }
    cout << 3*n << "\n";
    for(int i=1; i<=n; i+=2){
        cout << "1 " << i << " " << i+1 << "\n";
        cout << "2 " << i << " " << i+1 << "\n";
        cout << "1 " << i << " " << i+1 << "\n";
        cout << "1 " << i << " " << i+1 << "\n";
        cout << "2 " << i << " " << i+1 << "\n";
        cout << "1 " << i << " " << i+1 << "\n";
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