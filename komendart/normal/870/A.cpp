#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int ans = 100500;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                ans = min(ans, a[i]);
            } else {
                ans = min(ans, a[i] * 10 + b[j]);
                ans = min(ans, b[j] * 10 + a[i]);
            }
        }
    }
    cout << ans << '\n';
}