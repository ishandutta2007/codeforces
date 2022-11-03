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
    int am = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == 'a')
            am++;
    }
    cout << min((int)s.length(), 2 * am - 1) << '\n';


    return 0;
}