#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T --> 0) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
        int m = max(a.front(), n + 1 - a.back());
        for (int i = 0; i < k - 1; i++) {
            m = max(m, (a[i + 1] - a[i] + 2) / 2);
        }
        cout << m << '\n';
    }
}