#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s, t;
    cin >> s >> t;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == t[i]) cout << "0";
        else cout << "1";
    }
    cout << endl;

    return 0;
}