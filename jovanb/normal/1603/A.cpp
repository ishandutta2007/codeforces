#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    cin >> n;
    bool s = 1;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        bool m = 0;
        for(int j=2; j<=i+1; j++){
            if(x%j){
                m = 1;
                break;
            }
        }
        s &= m;
    }
    cout << (s == 1 ? "YES\n" : "NO\n");
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