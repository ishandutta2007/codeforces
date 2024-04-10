#include "bits/stdc++.h"
using namespace std;

bool check(int len, string &s){
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < min(len, (int)s.size()); ++i){
        if(s[i] == 'a') ++a;
        if(s[i] == 'b') ++b;
        if(s[i] == 'c') ++c;
    }

    if(a > b && a > c) return 1;

    for(int i = len; i < s.size(); ++i){
        if(s[i - len] == 'a') --a;
        if(s[i - len] == 'b') --b;
        if(s[i - len] == 'c') --c;

        if(s[i] == 'a') ++a;
        if(s[i] == 'b') ++b;
        if(s[i] == 'c') ++c;

        if(a > b && a > c) return 1;
    }

    return 0;
}

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    for(int i = 2; i <= 10; ++i) if(check(i, s)){
        cout << i << '\n';
        return;
    }

    cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}