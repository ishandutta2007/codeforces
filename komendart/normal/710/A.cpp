#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;

    int x = s[0] - 'a';
    int y = s[1] - '1';

    x = min(x, 7 - x);
    y = min(y, 7 - y);

    if (x == 0 && y == 0) cout << 3;
    else if (x == 0 || y == 0) cout << 5;
    else cout << 8;
}