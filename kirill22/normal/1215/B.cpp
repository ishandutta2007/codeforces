#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            a[i] = 1;
        }
        else {
            a[i] = -1;
        }
    }
    int x = 0,tmp = 0, s2 = 1;
    int s = ((n + 1) * n) / 2;
    for (int i = 0; i < n; i++) {
        s2 *= a[i];
        if (s2 > 0) {
            x += tmp;
        }
        else {
            x += (i + 1 - tmp);
        }
        if (s2 < 0) {
            tmp++;
        }
    }
    cout << x << " " << s - x;
}