#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--){
        int n;
        string s;
        cin >> n >> s;
        string a = s.substr(0,1), b = s.substr(1);
        if (n == 2 && a[0] >= b[0]) cout << "NO\n";
        else cout << "YES\n2\n" << a << ' ' << b << endl;
    }
}