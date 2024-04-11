#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (n == 4 || k <= n) {
        cout << -1 << '\n';
        return 0;
    }

    set<int> s;
    for (int i = 0; i < n; i++) s.insert(i + 1);
    s.erase(a); s.erase(b); s.erase(c); s.erase(d);

    cout << a << ' ' << c << ' ';
    for (auto i: s) cout << i << ' ';
    cout << d << ' ' << b << '\n';

    cout << c << ' ' << a << ' ';
    for (auto i: s) cout << i << ' ';
    cout << b << ' ' << d << '\n';
}