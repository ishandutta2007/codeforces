#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    string s;
    cin >> s;
    int c0 = 0, c1 = 0;
    for(auto c : s){
        if(c == '0') c0++;
        else c1++;
    }
    if(c0 == c1) cout << c0 - 1 << "\n";
    else cout << min(c0, c1) << "\n";
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