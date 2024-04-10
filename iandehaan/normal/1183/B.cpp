#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int cs = 0; cs < q; cs++) {
        int n, k;
        cin >> n >> k;
        int mn = __INT_MAX__;
        int mx = -1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        if (mn + k >= (mx - k)) {
            cout << mn + k << endl;
        } else {
            cout << -1 << endl;
        }
    }
}