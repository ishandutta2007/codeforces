#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int i, j, n, k, q;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> j;
        cin >> s;
        if (s.size() == 2 && s[0] >= s[1])
            cout << "NO\n";
        else {
            cout << "YES\n";
            cout << "2\n";
            cout << s[0] << ' ';
            for (j = 1; j < s.size(); ++j)
                cout << s[j];
            cout << "\n";
        }
    }
}