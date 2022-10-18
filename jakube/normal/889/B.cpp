#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (set<char>(v[i].begin(), v[i].end()).size() != v[i].size()) {
            cout << "NO" << endl;
            return 0;
        }
    }

    vector<bool> useit(256, false);
    vector<char> before(256, ' ');
    vector<char> after(256, ' ');
    for (auto s : v) {
        for (int i = 0; i < (int)s.size() - 1; i++) {
            int a = s[i];
            int b = s[i+1];
            if ((after[a] != ' ' && after[a] != b) || (before[b] != ' ' && before[b] != a)) {
                cout << "NO" << endl;
                return 0;
            }
            after[a] = b;
            before[b] = a;
            useit[a] = true;
            useit[b] = true;
        }
        useit[s[0]] = true;
    } 

    vector<char> res;
    for (int c = 'a'; c <= 'z'; c++) {
        if (useit[c] && before[c] == ' ') {
            auto d = c;
            while (useit[d]) {
                res.push_back(d);
                useit[d] = false;
                d = after[d];
            }
        }
    }

    for (int c = 'a'; c <= 'z'; c++) {
        if (useit[c]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << string(res.begin(), res.end()) << endl;

}