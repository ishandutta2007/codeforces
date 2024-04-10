#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    string res = "";
    bool beg = true;
    bool space = false;
    for (int i = 0; i < s.size();i++) {
        if (i + 2 < s.size() && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
            i += 2;
            space = true;
        } else {
            if (space && !beg) {
                res += ' ';
            }
            beg = false;
            space = false;
            res += s[i];
        }
    }

    cout << res << endl;


    return 0;
}