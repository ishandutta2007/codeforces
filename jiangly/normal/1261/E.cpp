#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    iota(b.begin(), b.end(), 0);
    sort(b.begin(), b.end(), [&](int i, int j) {return a[i] < a[j];});
    vector<vector<int>> c(n + 1);
    for (int i = 0; i <= n; ++i)
        c[i].resize(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < a[b[i]]; ++j)
            c[(n + 1 + i - j) % (n + 1)][b[i]] = 1;
    cout << n + 1 << "\n";
    for (int i = 0; i < n + 1; ++i, cout << "\n")
        for (int j = 0; j < n; ++j)
            cout << c[i][j];
    return 0;
}