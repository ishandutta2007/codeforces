#include <bits/stdc++.h>
using namespace std;
int a[5];
int main() {
    ios::sync_with_stdio(false);
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        int xx, yy;
        cin >> xx >> yy;
        if (xx > x) a[0]++;
        if (xx < x) a[1]++;
        if (yy > y) a[2]++;
        if (yy < y) a[3]++;
    }
    int mmax = 0;
    for (int i = 0; i < 4; i++) mmax = max(mmax, a[i]);
    cout << mmax << endl;
    if (a[0] == mmax) {
        cout << x + 1 << ' ' << y;
        return 0;
    } else if (a[1] == mmax) {
        cout << x - 1 << ' ' << y;
        return 0;
    } else if (a[2] == mmax) {
        cout << x << ' ' << y + 1;
        return 0;
    } else {
        cout << x << ' ' << y - 1;
        return 0;
    }
}