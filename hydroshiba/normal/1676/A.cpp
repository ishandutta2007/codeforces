#include "bits/stdc++.h"
using namespace std;

void solve(){
    string s;
    cin >> s;

    cout << (s[0] + s[1] + s[2] == s[3] + s[4] + s[5] ? "YES\n" : "NO\n");
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}