#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    unordered_set<int> values;
    for (int i = 0; i < n; i++) {
        int t; cin >> t; values.insert(t);
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        int result = k + 1;
        for (int m = 1; m <= k; m++) {
            for (int l = 0; l < m; l++) {
                for (int v: values) {
                    int r = x - v * l;
                    if (r % (m - l) == 0 && values.find(r / (m - l)) != values.end()) {
                        result = min(result, m);
                    }
                }
            }
        }
        cout << (result > k ? -1: result) << '\n';
    }
}