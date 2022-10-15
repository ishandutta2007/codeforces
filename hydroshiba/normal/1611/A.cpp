#include "bits/stdc++.h"
using namespace std;

void solve(){
    string s;
    cin >> s;

    if((*s.rbegin() - '0') % 2 == 0){
        cout << "0\n";
        return;
    }

    if((*s.begin() - '0') % 2 == 0){
        cout << "1\n";
        return;
    }

    for(char c : s) if((c - '0') % 2 == 0){
        cout << "2\n";
        return;
    }

    cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}