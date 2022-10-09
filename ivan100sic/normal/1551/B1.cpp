// Retired?
#include <bits/stdc++.h>
using namespace std;

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
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        int kec=0, sol=0;
        for (auto [k, v] : mp) {
            if (v == 1) {
                kec++;
            } else if (v >= 2) {
                sol++;
            }
        }

        cout << sol + (kec/2) << '\n';
    }
}