#include <bits/stdc++.h>
using namespace std;

int main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> cnta(300, 0), cntb(300, 0);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            cnta[a + 100]++;
        }
        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            cntb[b + 100]++;
        }
        bool f = true;
        for (int i = 0; i < 250; ++i) {
            if (cnta[i] < cntb[i]) {
                f = false;
                break;
            }
            if (cnta[i] == cntb[i]) continue;
            int x = cnta[i] - cntb[i];
            if (cntb[i + 1] < x) {
                f = false;
                break;
            }
            cntb[i + 1] -= x;
        }
        if (f) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}