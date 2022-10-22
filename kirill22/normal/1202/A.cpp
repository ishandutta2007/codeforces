#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string a, b;
        cin >> a >> b;
        int ii2 = 0;
        for (int j = 0; j < b.size(); j++) {
            if (b[j] == '1') {
                ii2 = j;
            }
        }
        int ii = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] == '1' && a.size() - j - 1 >= b.size() - ii2 - 1) {
                ii = j;
            }
        }
        ii = a.size() - ii - 1;
        ii2 = b.size() - ii2 - 1;
        //cout << ii << " " << ii2 << endl;
        cout << max(0ll, ii - ii2) << endl;
    }
}