#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5;

int n;
int x[maxn];
int y[maxn];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        int t, w; cin >> t >> w;
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        x[i] &= 1; if (x[i] < 0) x[i] += 2;
        y[i] &= 1; if (y[i] < 0) y[i] += 2;
        cout << 1 + x[i] * 2 + y[i] << '\n';
    }
}