#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int used[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        fill(used, used + n, 0);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            used[((a + i) % n + n) % n] = 1;
        }
        bool f = true;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}