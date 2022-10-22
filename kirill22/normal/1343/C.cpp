#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> k;
        int x = 0;
        for (int i = 0; i < n; i++) {
            int m = k.size();
            if (m == 0 || (k[m - 1] > 0 && a[i] < 0) || (k[m - 1] < 0 && a[i] > 0)) {
                k.push_back(a[i]);
                x += a[i];
            }
            else if (m != 0 && (!(k[m - 1] > 0 && a[i] < 0)) && (!(k[m - 1] < 0 && a[i] > 0))) {
                if (a[i] > k[m - 1]) {
                    x += a[i] - k[m - 1];
                    k[m - 1] = a[i];
                }
            }
        }
        cout << x << endl;
    }
}