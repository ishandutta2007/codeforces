#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.') cout << 0;
        else {
            i++;
            if (s[i] == '.')
                cout << 1;
            else
                cout << 2;
        }
    }

    return 0;
}