// Hydro submission #635a8cad49109e2d2cf5e1ce@1666878638003
#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    cin >> s;

    int len = s.size(), a = 0, b = 0, ret = 0;
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == 'a') {
            a++;
            ret++;
        }
        if (c == 'b') {
            b++;
        }
        ret = max(ret, b);
        b = max(b, a);
    }

    cout << ret;

    return 0;
}