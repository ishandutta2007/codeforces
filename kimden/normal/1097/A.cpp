#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    bool b = false;
    for(int i = 0; i < 5; ++i){
        string t;
        cin >> t;
        if (t[0] == s[0] || t[1] == s[1]) {
            b = true;
            break;
        }
    }
    if (b) {
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }


}