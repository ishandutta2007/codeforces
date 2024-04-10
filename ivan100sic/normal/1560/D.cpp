// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    vector<string> a;
    for (ll x=1; x<1e18; x*=2) {
        a.push_back(to_string(x));
    }
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int sol = 123123;
        for (string p : a) {
            int k = 0;
            for (char c : s) {
                if (k < (int)p.size() && p[k] == c) {
                    k++;
                }
            }

            sol = min(sol, (int)s.size() - k + (int)p.size() - k);            
        }

        cout << sol << '\n';
    }
}