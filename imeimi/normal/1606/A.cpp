#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        s[int(s.length()) - 1] = s[0];
        printf("%s\n", s.c_str());
    }
    return 0;
}