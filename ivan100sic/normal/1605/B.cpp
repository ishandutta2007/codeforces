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
        int n;
        string s;
        cin >> n >> s;
        string t = s;
        R::sort(t);
        if (t == s) {
            cout << "0\n";
        } else {
            cout << "1\n";
            vector<int> a;
            for (int i : ra(0, n)) {
                if (s[i] != t[i]) {
                    a.push_back(i);
                }
            }
            cout << size(a);
            for (int x : a) {
                cout << ' ' << x+1;
            }
            cout << '\n';
        }
    }
    
}