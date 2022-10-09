// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int k;
    cin >> k;
    map<char, int> mp;
    string s;
    cin >> s;
    for (int i=0; i<(int)s.size(); i++) {
        if (!mp.count(s[i])) {
            mp[s[i]] = i;
        }
    }

    if (k > (int)mp.size()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<int> v;
        for (auto [c, x] : mp) {
            v.push_back(x);
        }
        sort(begin(v), end(v));

        while ((int)v.size() > k) {
            v.pop_back();
        }
        v.push_back(s.size());

        for (int i=0; i<k; i++) {
            cout << s.substr(v[i], v[i+1] - v[i]) << '\n';
        }
    }
}