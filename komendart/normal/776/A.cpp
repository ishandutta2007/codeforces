#include <bits/stdc++.h>

using namespace std;

void out(set<string> d) {
    for (auto i: d) {
        cout << i << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    set<string> d = {a, b};
    for (int i = 0; i < n; ++i) {
        out(d);
        string a, b;
        cin >> a >> b;
        d.erase(a); d.insert(b);
    }
    out(d);
}