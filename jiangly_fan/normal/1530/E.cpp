#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        int n = s.size();
        sort(s.begin(), s.end());
        if (s[0] == s.back() or s[0] != s[1]) {
            cout << s << "\n";
            continue;
        }
        int ok = 0;
        for (int j = 0; j < 26; j += 1)
            if (count(s.begin(), s.end(), 'a' + j) == 1){
                cout << char('a' + j);
                for (int k = 0; k < n; k += 1) if (s[k] != 'a' + j) cout << s[k];
                cout << "\n";
                ok = 1;
                break;
            }
        if (ok) continue;
        int c = 0;
        while(c < n and s[c] == s[0]) c += 1;
        string t = s.substr(0, 1);
        if (c <= n - c + 2) {
            int i = c;
            for (int j = 1; j < c; j += 1) {
                t += s[0];
                if (i < n) t += s[i ++];
            }
            while (i < n) t += s[i ++];
        }
        else if (s[c] == s.back()) {
            int i = c;
            while (i < n) t += s[i ++];
            for (int j = 1; j < c; j += 1) t += s[0];
        }
        else {
            int d = c;
            while (d < n and s[d] == s[c]) d += 1;
            int j = d;
            t += s[c];
            for (int k = 1; k < c; k += 1) t += s[0];
            t += s[j ++];
            for (int k = 1; k < d - c; k += 1) t += s[c];
            while (j < n) t += s[j ++];
        }
        assert(s.size() == t.size());
        cout << t << "\n";
    }
    return 0;
}