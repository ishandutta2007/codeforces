#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int d[400000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, l;
        cin >> n >> k >> l;
        bool ok = 1;
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
            d[i] = l - d[i];
            if (d[i] < 0) ok = 0;
        }
        if (!ok) {
            cout << "No" << endl;
            continue;
        }
        bool f = 1;
        bool luo = 1;
        int now = min(k, d[1]);
        int p = 1;
        while (p <= n) {
            if (d[p] >= k) {
                while (p <= n && d[p] >= k) p++;
                luo = 1;
                now = k - 1;
                continue;
            }
            if (luo) {
                now = min(now, d[p]);
                if (now == 0) {
                    luo = 0;
                    now = 1;
                    p++;
                    continue;
                }
                now--;
            } else {
                if (now > d[p]) {
                    f = 0;
                    break;
                }
                if (now == k) {
                    luo = 1;
                    now--;
                    p++;
                    continue;
                }
                now++;
            }
            p++;
        }
        if (f)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}