#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e3;
int arr[MAXN][MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    // cout << 999 * 999 << endl;
    for (int i = 0; i < n; ++i) {
        int x = (i + 1) % n;
        int y = (i + 2) % n;
        int res = arr[i][x] * arr[i][y] / arr[x][y];
        // cout << arr[i][x] << " " << arr[i][y] << " " << arr[x][y] << endl;
        // cout << res << endl;
        res = trunc(sqrt(res));
        cout << res << " ";
    }
    return 0;
}