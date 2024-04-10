#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int t = 0;
    for(auto c : s) if(c == '0') t++;
    if(t == 1 || t%2 == 0) cout << "BOB\n";
    else cout << "ALICE\n";
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