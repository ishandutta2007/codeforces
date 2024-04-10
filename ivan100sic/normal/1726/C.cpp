// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct union_find {
    vector<int> p;
    union_find(int n) : p(n) { iota(begin(p), end(p), 0); }
    bool operator() (int x, int y) { return e(x) == e(y); }
    int e(int x) {
        if (p[x] == x) return x;
        return p[x] = e(p[x]);
    }
    bool join(int x, int y) {
        x = e(x), y = e(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> b;
        union_find uf(2*n);
        int cmp = 2*n;

        auto jn = [&](int i, int j) {
            if (uf.join(i, j)) {
                cmp--;
            }
        };

        for (int i : ra(0, 2*n)) {
            if (s[i] == '(') {
                b.push_back(i);
                if (i > 0 && s[i-1] == ')') {
                    jn(i, i-1);
                }
            } else {
                jn(i, b.back());
                b.pop_back();
            }
        }

        cout << cmp << '\n';
    }
    
}