#include <bits/stdc++.h>

using namespace std;

string normalize(string s) {
    for (auto &c: s) {
        c = tolower(c);
        if (c == '0') c = 'o';
        if (c == '1' || c == 'i') c = 'l';
    }
    return s;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string kek;
    cin >> kek;
    kek = normalize(kek);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string lol; cin >> lol;
        lol = normalize(lol);
        if (kek == lol) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

}