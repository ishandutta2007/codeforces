#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> ans(n);
        if (n % 4 != 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i < n / 2) {
                cout << i * 2 + 2 << " ";
                res += i * 2 + 2;
            }
            else {
                cout << (i - n / 2) * 2 + 1 << " ";
                res -= (i - n / 2) * 2 + 1;
            }
        }
        cout << res;
        cout << endl;
    }
}