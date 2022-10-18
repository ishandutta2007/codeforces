#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    char last = 'a' - 1;
    for (char c : s) {
        if (c > last + 1) {
            cout << "NO" << endl;
            return 0;
        }
        last = max(c, last);
    }

    cout << "YES" << endl;

    return 0;
}