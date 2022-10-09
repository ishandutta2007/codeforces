// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct node {
    int l, r, d;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }

        vector<node> sol;

        for (int i=0; i<n; i++) {
            int j = min_element(a.begin() + i, a.end()) - a.begin();
            if (j != i) {
                sol.push_back({i+1, j+1, j-i});
                rotate(a.begin() + i, a.begin() + j, a.begin() + j + 1);
            }
        }

        cout << sol.size() << '\n';
        for (auto [l, r, d] : sol) {
            cout << l << ' ' << r << ' ' << d << '\n';
        }
    }
}