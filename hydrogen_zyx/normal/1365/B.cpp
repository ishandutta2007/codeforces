#include <bits/stdc++.h>
using namespace std;
int a[1000], b[1000];
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        int o1 = 0, o2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i])
                o1++;
            else
                o2++;
        }
        if (o1 * o2) {
            cout << "Yes" << endl;
        } else {
            int ok = 0;
            for (int i = 1; i < n; i++) {
                if (a[i] < a[i - 1]) {
                    ok = 1;
                    break;
                }
            }
            if (ok) {
                cout << "No" << endl;
            } else
                cout << "Yes" << endl;
        }
    }
}