// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        vector<int> qm;
        int z = 0;
        for (int i : ra(0, ssize(s))) {
            if (s[i] == '?') {
                qm.push_back(i);
            } else if (s[i] == '(') {
                z += 1;
            } else {
                z -= 1;
            }
        }

        int op = (ssize(qm) - z) / 2;
        int cl = ssize(qm) - op;
    
        if (op == 0 || cl == 0) {
            cout << "YES\n";
            continue;
        }

        string t = s;
        for (int i : ra(0, op-1)) t[qm[i]] = '(';
        t[qm[op-1]] = ')';
        t[qm[op]] = '(';
        for (int i : ra(op+1, ssize(qm))) t[qm[i]] = ')';

        z = 0;
        bool neg = 0;
        for (char c : t) {
            z += c == '(' ? 1 : -1;
            if (z < 0) {
                neg = 1;
            }
        }

        if (neg) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}