#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    long long mi = std::numeric_limits<long long>::max();
    for (int i = 0; i < n; i++) {
        long long ma = std::numeric_limits<long long>::min();
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            for (int k = 0; k < m; k++) {
                long long cur = (long long)a[j] * b[k];
                ma = max(ma, cur);
            }
        }
        mi = min(mi, ma);
    }
    cout << mi << endl;
}