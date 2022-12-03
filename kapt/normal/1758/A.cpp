#include <bits/stdc++.h>
using namespace std;

int main() {
    int tst;
    cin >> tst;
    while (tst--) {
        string s;
        cin >> s;
        cout << s;
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}