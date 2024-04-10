#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n, k;
    cin >> n >> k;
    if(k > (n+1)/2){
        cout << "-1\n";
        return;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j && i%2 && k > 0) cout << "R", k--;
            else cout << ".";
        }
        cout << "\n";
    }
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