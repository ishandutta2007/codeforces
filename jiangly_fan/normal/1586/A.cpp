#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 20000;
int p[maxn + 1];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 4; i <= maxn; i += 1)
        for (int j = 2; j < i; j += 1) if (i % j == 0) {
            p[i] = 1;
            break;
        }
    int t;
    for (cin >> t; t; t -= 1) {
        int n, sum = 0;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
            sum += x;
        }
        if (p[sum]) {
            cout << n << "\n";
            for (int i = 1; i <= n; i += 1) cout << i << " ";
            cout << "\n";
        }
        else {
            for (int i = 0; i < n; i += 1) if (p[sum - a[i]]) {
                cout << n - 1 << "\n";
                for (int j = 0; j < n; j += 1) if (j != i) cout << j + 1 << " ";
                cout << "\n";
                break;
            }
        }
    }
    return 0;
}