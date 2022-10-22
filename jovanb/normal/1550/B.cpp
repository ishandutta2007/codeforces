#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    int res = n*a;
    string s;
    cin >> s;
    char tr = 'z';
    int comps = 0;
    for(auto c : s){
        if(c != tr) comps++;
        tr = c;
    }
    if(b >= 0){
        cout << res + n*b << "\n";
        return;
    }
    cout << res + b*((comps+2)/2) << "\n";
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