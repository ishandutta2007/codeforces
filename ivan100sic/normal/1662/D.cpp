// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

/*
acacacaaccca
acacac  ccca
acacacccca
acaca    a
acac

bcbabcbbbbabcbab
acacac


*/

string base(string t) {
    int b = 0;
    string s;
    for (char c : t) {
        if (c == 'B') {
            b ^= 1;
        } else {
            if (s.size() && s.back() == c) {
                s.pop_back();
            } else {
                s.push_back(c);
            }
        }
    }
    if (b) s += 'b';
    return s;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string u, v;
        cin >> u >> v;

        cout << (base(u) == base(v) ? "YES\n" : "NO\n");
    }
}