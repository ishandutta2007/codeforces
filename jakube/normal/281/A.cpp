#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    if (s[0] >= 'a' && s[0] <= 'z') 
        s = (char)(s[0] - 'a' + 'A') + s.substr(1);
    cout << s << endl;

    return 0;
}