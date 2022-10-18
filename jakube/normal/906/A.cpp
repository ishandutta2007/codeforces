#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int cnt = 0;
    vector<bool> letters(26, true);
    bool finished = false;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        string s;
        cin >> s;
        vector<bool> letters2(26, false);
        for (char d : s) {
            letters2[d - 'a'] = true;
        }

        if (c == '.') {
            for (int l = 0; l < 26; l++) {
                if (letters2[l])
                    letters[l] = false;
            }
        }
        if (c == '!') {
            if (finished)
                cnt++;
            for (int l = 0; l < 26; l++) {
                if (!letters2[l])
                    letters[l] = false;
            }
        }
        if (c == '?') {
            if (!letters[s[0] - 'a'] && finished)
                cnt++;
            letters[s[0] - 'a'] = false;
        }

        // test
        int cc = 0;
        for (auto b : letters) {
            if (b)
                cc++;
        }

        if (cc <= 1) {
            finished = true;
        }
    }
    cout << cnt << endl;
}