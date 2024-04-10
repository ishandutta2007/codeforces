#include<bits/stdc++.h>

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
        int l = 0, r = 0;
        for (auto c : s) {
            l += (c - 'a' + 1);
        }
        if ((int) s.size() % 2 == 1) {
            r = min(s[0], s.back()) - 'a' + 1;
            l -= r;
        }
        cout << (l > r ? "Alice " : "Bob ") << abs(r - l) << '\n';
    }
}