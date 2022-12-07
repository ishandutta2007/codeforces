#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        char letters = 'z';
        for (int i = 0; i < s.length(); i++) {
            letters = min(letters, s[i]);
        }
        cout << letters << " ";
        for (int i = 0; i < s.length(); i++) {
            if (letters != s[i]) {
                cout << s[i];
            } else {
                letters = '1';
            }
        }
        cout << endl;
    }
    return 0;
}