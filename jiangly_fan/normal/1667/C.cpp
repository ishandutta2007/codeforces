#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //k >= (n - k) * 2 - 1
    //3k >= 2 * n - 1
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n1 1";
        return 0;
    }
    int k = (2 * n + 1) / 3;
    cout << k << "\n";
    int m = n - k;
    for (int i = 1; i <= m - 1; i += 1) {
        cout << i << " " << m - i << "\n";
    }
    for (int i = m; i <= 2 * m - 1; i += 1) {
        cout << i << " " << 3 * m - 1 - i << "\n";
    }
    for (int i = 2 * m; i <= k; i += 1)
        cout << i << " " << i << "\n";
}