#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int n, te, k, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> te;
    a[0] = -1;
    while (te--) {
        cin >> n >> k;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt += (i >= 2 && a[i] != a[i - 1]);
        }
        if (k == 1) {
            cout << (cnt == 0 ? 1 : -1) << '\n';
        } else {
            int tmp = cnt / (k - 1);
            // cout << cnt << " " << tmp << '\n';
            if (tmp * (k - 1) < cnt) {
                tmp++;
            }
            cout << max(tmp, 1) << '\n';
        }
    }
}