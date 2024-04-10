#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        auto s = to_string(n);
        if (s.size() == 2) cout << s[1] << "\n";
        else cout << ranges::min(s) << "\n";
    }
    return 0;
}