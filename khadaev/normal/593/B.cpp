#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x1, x2, k[100000], b[100000];
    cin >> n >> x1 >> x2;
    for (int i = 0; i < n; ++i) cin >> k[i] >> b[i];
    pair<long long, long long> values[100000];
    for (int i = 0; i < n; ++i) {
        long long v1 = k[i] * x1 + b[i];
        long long v2 = k[i] * x2 + b[i];
        values[i] = {v1, v2};
    }
    sort(values, values + n);
    for (int i = 0; i < n - 1; ++i)
        if (values[i].second > values[i + 1].second) {
            cout << "YES\n";
            return 0;
        }
    cout << "NO\n";
    return 0;
}