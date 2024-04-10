#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), std::cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<vector<int>, int> d;
    for (int i = 0; i < 32768; ++i) {
        vector<int> x(n - 1);
        int t = __builtin_popcount(i ^ (a[0] & 32767));
        for (int j = 1; j < n; ++j)
            x[j - 1] = __builtin_popcount(i ^ (a[j] & 32767)) - t;
        d[x] = i;
    }
    for (int i = 0; i < 32768; ++i) {
        vector<int> x(n - 1);
        int t = __builtin_popcount(i ^ (a[0] >> 15));
        for (int j = 1; j < n; ++j)
            x[j - 1] = t - __builtin_popcount(i ^ (a[j] >> 15));
        auto it = d.find(x);
        if (it != d.end()) {
            cout << 32768 * i + it->second << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}