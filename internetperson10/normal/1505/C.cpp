#include <bits/stdc++.h>

using namespace std;

int main() {
    bool sad = false;
    string s;
    cin >> s;
    int x, y, a;
    x = y = a = -1;
    for(int i = 0; i < s.size(); i++) {
        a = x;
        x = y;
        y = (s.at(i) - 'A');
        if(a == -1) continue;
        if((a+x)%26 != y) sad = true;
    }
    if(sad) cout << "NO\n";
    else cout << "YES\n";
}