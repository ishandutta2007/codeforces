#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, w;
    cin >> n >> m >> w;

    vector<int> a(n);
    for (int idx = 0; idx < n; idx++)
        cin >> a[idx];
    
    int L = *min_element(a.begin(), a.end());
    int R = (1e9 + 1e5 + 1);
    // L is possible
    while (L + 1 < R) {
        int M = (L + R) / 2;
        vector<int> used(n, 0);

        int days = 0;
        int cur = 0;

        for (int i = 0; i < n; i++) {
            if (i >= w) cur -= used[i - w];
            if (a[i] + cur < M) {
                int tmp = M - cur - a[i];
                days += tmp;
                used[i] = tmp;
                cur += tmp;
                if (days > m)
                    break;
            }
        }

        if (days > m) {
            R = M;
        } else {
            L = M;
        }
    }

    cout << L << endl;

    return 0;
}