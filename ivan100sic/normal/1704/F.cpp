// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct mexer {
    vector<int> a;
    void operator+= (int x) { a.push_back(x); }
    int operator() () const {
        int n = a.size();
        vector<char> u(n);
        for (int x : a) if (x < n) u[x] = 1;
        return find(begin(u), end(u), 0) - begin(u);
    }
};

int d[34*4];

void pcp() {
    for (int w : ra(1, 34*4)) {
        mexer mx;
        for (int x : ra(0, w)) {
            int l = max(0, x-1);
            int r = max(0, w-x-2);
            mx += d[l] ^ d[r];
        }
        d[w] = mx();
    }
}

int nb(int x) {
    if (x < 34*4) return d[x];
    return d[x%34+3*34];
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    pcp();

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int cr = R::count(s, 'R');
        int cb = R::count(s, 'B');

        if (cr > cb) {
            cout << "Alice\n";
            continue;
        } else if (cr < cb) {
            cout << "Bob\n";
            continue;
        }

        int streak = 0;
        int nim = 0;
        for (int i : ra(0, n-1)) {
            if (s[i] != s[i+1]) {
                streak++;
            } else {
                nim ^= nb(streak);
                streak = 0;
            }
        }

        nim ^= nb(streak);

        cout << (nim ? "Alice\n" : "Bob\n");
    }
}