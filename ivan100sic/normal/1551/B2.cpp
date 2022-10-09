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
        map<int, vector<int>> mp;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            if ((int)mp[x].size() < k) {
                mp[x].push_back(i);
            }
        }
        vector<pair<int, int>> paints;
        int idx = 0;
        for (auto [_, v] : mp) {
            for (int x : v) {
                paints.emplace_back(x, idx++ % k + 1);
            }
        }
        vector<int> a(n);
        paints.resize(paints.size() / k * k);
        for (auto [x, c] : paints) {
            a[x] = c;
        }
        for (int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}