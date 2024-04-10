#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    
    cout << ((s.find('H') != s.npos || s.find('Q') != s.npos || s.find('9') != s.npos) ? "YES" : "NO") << endl;

    return 0;
}