// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll steps(const string& s, string p) {
    map<char, int> ord;
    for (int i=0; i<(int)p.size(); i++) {
        ord[p[i]] = i;
    }

    ll z = 0;

    vector<int> c(4);
    for (char x : s) {
        for (int j=ord[x]+1; j<4; j++) {
            z += c[j];
        }
        c[ord[x]]++;
    }

    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        map<char, int> mp;
        for (char c : s) mp[c]++;
        string p, pp;
        for (auto [k, v] : mp) p += k;
        ll z = -1;
        do {
            ll st = steps(s, p);
            if (st > z) {
                z = st;
                pp = p;
            }
        } while (next_permutation(begin(p), end(p)));

        for (char c : pp) {
            cout << string(mp[c], c);
        }
        cout << '\n';
    }
}