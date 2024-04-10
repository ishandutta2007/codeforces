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
        int n, k;
        cin >> n >> k;
        set<int> s;
        vector<pair<int, int>> ch;
        for (int i=1; i<=2*n; i++) s.insert(i);
        for (int i=0; i<k; i++) {
            int x, y;
            cin >> x >> y;
            ch.emplace_back(x, y);
            s.erase(x);
            s.erase(y);
        }
        vector<int> v(begin(s), end(s));
        for (int i=0; i<(int)v.size()/2; i++) {
            // cerr << "added " << v[i] << ' ' << v[i + v.size() / 2] << '\n';
            ch.emplace_back(v[i], v[i + v.size() / 2]);
        }

        int z = 0;

        auto dir = [&](int x, int y, int z) {
            if (x < y) return y < z || z < x;
            else return !(x < z || z < y);
        };

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                auto [x, y] = ch[i];
                auto [p, q] = ch[j];
                
                if (dir(x, y, p) != dir(x, y, q)) {
                    z++;
                }
            }
        }

        cout << z << '\n';
    }
}