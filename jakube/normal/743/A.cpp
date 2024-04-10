#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, a, b;
    cin >>  n >> a >> b;

    a--;
    b--;
    string s;
    cin >> s;

    if (s[a] == s[b]) {
        cout << 0 << endl;
        return 0;
    }

    cout << 1 << endl;

    return 0;
}