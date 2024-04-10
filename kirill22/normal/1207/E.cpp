#include <bits/stdc++.h>

using namespace std;

#define int long long

int N = (1 << 14) - 1;

signed main() {
    cout << "?" << " ";
    for (int i = 0; i < 100; i++) {
        cout << i << " ";
    }
    cout << endl;
    fflush(stdout);
    int res;
    cin >> res;
    if (res == -1) {
        return 0;
    }
    cout << "?" << " ";
    for (int i = 1; i <= 100; i++) {
        cout << (i << 7) << " ";
    }
    cout << endl;
    fflush(stdout);
    int res2;
    cin >> res2;
    if (res2 == -1) {
        return 0;
    }
    int ans = 0, k = 7;
    for (int i = 7; i > 0; i--) {
        if (res2 % 2 == 1) {
            ans += (1 << (7 - i));
        }
        res2 /= 2;
        res /= 2;
    }
    for (int i = 7; i > 0; i--) {
        if (res % 2 == 1) {
            ans += (1 << (7 - i + 7));
        }
        res /= 2;
    }
    cout << "! " << ans;
    fflush(stdout);
    return 0;
}