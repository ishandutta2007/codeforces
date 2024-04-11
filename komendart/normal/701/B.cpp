#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    set<int> a, b;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a.insert(x);
        b.insert(y);
        cout << n * n - (int) a.size() * n - (int) b.size() * (n - (int) a.size()) << ' ';
    }
}