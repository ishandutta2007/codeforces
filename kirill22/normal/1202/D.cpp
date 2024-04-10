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
        int n;
        cin >> n;
        vector<int> t;
        int tmp = 1e5;
        while (tmp >= 2) {
            while (tmp * (tmp - 1) <= n * 2 && n > 0) {
                t.push_back(tmp);
                n -= (tmp * (tmp - 1)) / 2;
            }
            tmp--;
        }
        cout << 1;
        int k = 0;
        for (int i = t.size() - 1; i >= 0; i--) {
            while (k < t[i]) {
                cout << 3;
                k++;
            }
            cout << 7;
        }
        cout << endl;
    }
}