#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        vector<char> b(100, 'A');
        int j = 50;
        bool f = true;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                b[j] = s[i];
                continue;
            }
            if (b[j - 1] == s[i]) {
                j--;
                continue;
            }
            if (b[j + 1] == s[i]) {
                j++;
                continue;
            }
            if (b[j - 1] == 'A') {
                j--;
                b[j] = s[i];
                continue;
            }
            if (b[j + 1] == 'A') {
                j++;
                b[j] = s[i];
                continue;
            }
            f = false;
        }
        vector<int> used(26, 0);
        for (auto el : b) {
            if (el == 'A') continue;
            used[el - 'a']++;
            if (used[el - 'a'] > 1) {
                    f = false;
            }
        }
        if (!f) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (auto el : b) {
            if (el != 'A') cout << el;
        }
        for (int i = 0; i < 26; i++) {
            if (used[i] == 0) {
                cout << char(i + 'a');
            }
        }
        cout << endl;
    }
}