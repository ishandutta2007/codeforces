#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        for (auto& c : s) {
            c = tolower(c);
        }
        cout << (s == "yes" ? "YES\n" : "NO\n");
    }
}