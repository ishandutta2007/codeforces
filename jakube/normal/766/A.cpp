#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s, t;
    cin >> s >> t;
    
    if (s == t) {
        cout << -1 << endl;
    } else {
        cout << max(s.size(), t.size()) << endl;
    }

    return 0;
}