// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

string run(string s, string p) {
    string t;
    for (char c : p) {
        t += s;
        s.erase(remove_if(begin(s), end(s), [&](char x) { return x == c; }), s.end());
    }
    return t;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string p;
        for (int i=(int)s.size()-1; i>=0; i--) {
            if (!count(begin(p), end(p), s[i])) {
                p += s[i];
            }
        }

        reverse(begin(p), end(p));

        int l = 1, r = s.size(), o = 0;
        while (l <= r) {
            int m = (l+r) / 2;
            string z = run(s.substr(0, m), p);
            if (z.size() > s.size()) {
                r = m - 1;
            } else {
                o = m;
                l = m + 1;
            }
        }

        string ru = run(s.substr(0, o), p);
        if (ru == s) {
            cout << s.substr(0, o) << ' ' << p << '\n';
        } else {
            cout << "-1\n";
        }
    }
}