#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        uint64_t sm = 0;
        int i;
        for (i = 0; i < n; i++) {
            sm += a[i];
            if (sm > s) break;
        }
        if (i == n) {
            cout << 0 << endl;
            continue;
        }

        int mx = 0;
        for (int j = 1; j <= i; j++) {
            if (a[j] > a[mx]) {
                mx = j;
            }
        }
        cout << mx+1 << endl;

    }
}