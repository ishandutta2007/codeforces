#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;
    string res;
    res += s[0];

    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] >= t[0])
            break;
        res += s[i];
    }
    res += t[0];
    cout << res << '\n';
}