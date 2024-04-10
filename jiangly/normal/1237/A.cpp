#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = (a[i] - (a[i] & 1)) / 2;
        sum += b[i];
    }
    for (int i = 0; i < n; ++i)
        if (2 * b[i] != a[i] && sum < 0) {
            ++b[i];
            ++sum;
        }
    for (int i = 0; i < n; ++i) cout << b[i] << "\n";
    return 0;
}