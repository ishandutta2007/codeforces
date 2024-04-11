#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n, k, a, m;
    cin >> n >> k >> a >> m;

    set<int> borders = {0, n + 1};
    int result = (n + 1) / (a + 1);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (borders.find(x) != borders.end()) continue;
        auto it = borders.upper_bound(x);
        int r = *it; it--; int l = *it;
        result -= (r - l) / (a + 1);
        result += (x - l) / (a + 1);
        result += (r - x) / (a + 1);
        borders.insert(x);
        if (result < k) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}