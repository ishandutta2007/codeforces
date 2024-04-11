#include <bits/stdc++.h>

using namespace std;

#define int long long

void out(int x) {
    cout << x << '\n';
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = 0;
    for (auto i: a) {
        if (i / 2 <= x) {
            x -= i / 2;
            if (i % 2 == 1) {
                if (y > 0) y--;
                else if (x > 0) x--;
                else out(ans);
            }
        } else {
            i -= 2 * x;
            x = 0;
            if (i > y) out(ans);
            y -= i;
        }
        ans++;
    }

    out(ans);
}