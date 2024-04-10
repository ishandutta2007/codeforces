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
        int n;
        cin >> n;
        set<pair<int, int>> s;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x) {
                s.insert({x, i});
            }
        }
        
        vector<pair<int, int>> sol;

        while (s.size() > 1) {
            auto [al, il] = *s.begin();
            s.erase(s.begin());
            auto [ar, ir] = *--s.end();
            s.erase(--s.end());

            sol.push_back({il, ir});
            al--;
            ar--;
            if (al) s.insert({al, il});
            if (ar) s.insert({ar, ir});
        }

        cout << sol.size() << '\n';
        for (auto [x, y] : sol) {
            cout << x << ' ' << y << '\n';
        }
    }
}