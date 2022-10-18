#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto simplyfy = [](string s) {
        for (char& c : s) {
            if (c >= 'a' && c <= 'z')
                c = c - 'a' + 'A';
            if (c == 'O')
                c = '0';
            if (c == 'L' || c == 'I')
                c = '1';
        }
        return s;
    };

    string s;
    cin >> s;
    s = simplyfy(s);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        if (s == simplyfy(t)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << '\n';
}