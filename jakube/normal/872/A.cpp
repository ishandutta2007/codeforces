#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int res = 999;
    for (int x : a) {
        for (int y : b) {
            if (x == y) {
                res = min(res, x);
            }
            res = min(res, x*10 + y);
            res = min(res, y*10 + x);
        }
    }
    cout << res << endl;

}