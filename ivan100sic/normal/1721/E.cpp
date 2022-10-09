// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class V>
vector<int> prefix_function(const V& v) {
    int n = v.size();
    vector<int> f(n+1);
    f[0] = -1;
    for (int i=1; i<=n; i++) {
        int r = f[i-1];
        while (r != -1 && v[r] != v[i-1]) r = f[r];
        f[i] = r+1;
    }
    return f;
}

const int inf = 1123123123;

string s;
int n;
int e[1000015][26];
int f[1000015];

int ep(int i, char c) {
    if (i == -1) return -1;
    
    if (s[i] == c) {
        return i;
    }

    int& tgt = e[i][c-'a'];
    if (tgt != -inf) {
        return tgt;
    }

    return tgt = ep(f[i], c);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> s;
    n = ssize(s);

    R::fill(e[0], -inf);
    f[0] = -1;

    auto go = [&](auto lr) {
        for (int i : lr) {
            R::fill(e[i], -inf);
            int r = f[i-1];
            r = ep(r, s[i-1]);
            f[i] = r+1;
        }
    };

    go(ra(1, n+1));

    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        s += t;
        auto lr = ra(n+1, n+ssize(t) + 1);
        go(lr);
        for (int i : lr) {
            cout << f[i] << ' ';
        }
        cout << '\n';
        s.erase(n);    
    }
}