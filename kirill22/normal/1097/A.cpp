#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ok = 0;
    string s;
    cin >> s;
    for (int i = 0; i < 5; i++) {
        string t;
        cin >> t;
        ok |= (s[0] == t[0]);
        ok |= (s[1] == t[1]);
    }
    cout << (ok ? "YES" : "NO");
}