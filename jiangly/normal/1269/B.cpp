#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int x = m;
    for (int i = 0; i < n; ++i) {
        [&]() {
            int val = (b[i] - a[0] + m) % m;
            for (int j = 1; j < n; ++j)
                if ((b[(j + i) % n] - a[j] + m) % m != val)
                    return;
            x = min(x, val);
        }();
    }
    cout << x << "\n";
    return 0;
}