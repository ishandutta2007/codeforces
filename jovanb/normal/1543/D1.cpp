#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n, K;
    cin >> n >> K;
    int pref = 0;
    for(int i=0; i<n; i++){
        cout << (i^pref) << endl;
        int x;
        cin >> x;
        if(x != 0) return;
        pref ^= (i^pref);
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