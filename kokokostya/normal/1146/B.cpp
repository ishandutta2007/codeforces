#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    string t = "";
    int cnt = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] != 'a')
            cnt++;
    }
    if (cnt % 2 == 1) {
        cout << ":(\n";
        return 0;
    }
    cnt /= 2;
    for (int i = 0; i < (int)s.length();i++) {
        if (s[i] != 'a') {
            if (cnt == 0) {
                break;
            }
            cnt--;
        }
        t += s[i];
    }

    string some = t;
    for (char c : t) {
        if (c != 'a')
            some += c;
    }
    if (s == some) {
        cout << t << '\n';
    }
    else {
        cout << ":(\n";
    }

    return 0;
}