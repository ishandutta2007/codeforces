#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    if(s.size() & 1){
        cout << "NO\n";
        return;
    }

    for(int i = 0; i < s.size() / 2; ++i){
        if(s[i] != s[i + s.size() / 2]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}