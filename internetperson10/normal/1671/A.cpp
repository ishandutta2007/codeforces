#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    string s;
    cin >> s;
    bool ok = true;
    for(int i = 0; i < s.size(); i++) {
        bool che = false;
        if(i+1 < s.size()) {
            if(s[i] == s[i+1]) che = true;
        }
        if(i) {
            if(s[i] == s[i-1]) che = true;
        }
        if(!che) ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}