#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3;
int ans[MAXN][MAXN];

main() {
    int n;
    cin >> n;
    int arr[] = {8, 9, 1, 13, 3, 12, 7, 5, 0, 2, 4, 11, 6, 10, 15, 14};
    int k = n / 4;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int r = i * 4 + j;
            r = arr[r];
            for (int i1 = 0; i1 < k; ++i1) {
                for (int j1 = 0; j1 < k; ++j1) {
                    int x = i1 * k + j1;
                    ans[i * k + i1][j * k + j1] = x * 16 + r;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}