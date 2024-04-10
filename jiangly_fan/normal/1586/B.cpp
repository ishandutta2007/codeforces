#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        set<int> s;
        for (int i = 1; i <= n; i += 1) s.insert(i);
        for (int i = 0, a, b, c; i < m; i += 1) {
            cin >> a >> b >> c;
            s.erase(b);
        }
        for (int i = 1; i <= n; i += 1) if (i != *s.begin()) cout << i << " " << *s.begin() << "\n";
    }
    return 0;
}