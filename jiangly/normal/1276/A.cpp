#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin >> s;
    vector<int> t;
    for (int i = 0; i + 2 < s.length(); ++i) {
        if (i + 4 < s.length() && s.substr(i, 5) == "twone") {
            t.push_back(i + 3);
            s[i + 2] = 'a';
        }
        if (s.substr(i, 3) == "two")
            t.push_back(i + 2);
        if (s.substr(i, 3) == "one")
            t.push_back(i + 2);
    }
    cout << t.size() << "\n";
    for (int i : t)
        cout << i << " ";
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}