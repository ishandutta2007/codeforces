#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int c = 1, m = k;
    while (m < n) {
        m *= k;
        c += 1;
    }
    cout << c << "\n";
    for (int i = 1; i <= n; i += 1)
        for (int j = i + 1; j <= n; j += 1) {
            int p = i - 1, q = j - 1, x = 0;
            while (p != q) {
                p /= k;
                q /= k;
                x += 1;
            }
            cout << x << " ";
        }
    return 0;
}