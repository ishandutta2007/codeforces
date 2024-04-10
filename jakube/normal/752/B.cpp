#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s, t;
    cin >> s >> t;

    map<char, char> m;
    for (int i = 0; i < s.size(); i++) {
            if ((m.count(s[i]) && m[s[i]] != t[i]) || (m.count(t[i]) && m[t[i]] != s[i])) {
                cout << -1 << endl;
                return 0;
            }
            m[s[i]] = t[i];
            m[t[i]] = s[i];
    }

    vector<bool> b(26, false);
    vector<pair<char, char>> res;
    for (char c = 'a'; c <= 'z'; c++) {
        if (m.count(c) && !b[c-'a'] && m[c] != c) {
            res.push_back({c, m[c]});
            b[c-'a'] = true;
            b[m[c]-'a'] = true;
        }
    }
    cout << res.size() << endl;
    for (auto p : res) 
        cout << p.first << " " << p.second << endl;
    return 0;
}