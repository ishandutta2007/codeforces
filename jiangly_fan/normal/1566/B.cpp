#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    for (cin >> T; T; T -= 1) {
        string s;
        cin >> s;
        int z = 0;
        for (int i = 0; i < (int)s.size(); i += 1)
            if (s[i] == '0' and (i == 0 or s[i] != s[i - 1])) z += 1;
        cout << min(z, 2) << "\n";
    }
    return 0;
}