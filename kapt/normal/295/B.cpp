#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 500;
int a[MAXN][MAXN];
int ord[MAXN], ans[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> ord[i];
        ord[i]--;
    }
    reverse(ord, ord + n);
    int k, nowans;
    for (int ind = 0; ind < n; ++ind) {
        nowans = 0;
        k = ord[ind];
        for (int i = 0; i <= ind; ++i) {
            for (int j = 0; j <= ind; ++j) {
                a[ord[j]][k] = min(a[ord[j]][k], a[ord[i]][k] + a[ord[j]][ord[i]]);
                a[k][ord[j]] = min(a[k][ord[j]], a[k][ord[i]] + a[ord[i]][ord[j]]);
            }
        }
        for (int i = 0; i <= ind; ++i) {
            for (int j = 0; j <= ind; ++j) {
                a[ord[i]][ord[j]] = min(a[ord[i]][ord[j]], a[ord[i]][k] + a[k][ord[j]]);
            }
        }
        for (int i = 0; i <= ind; ++i) {
            for (int j = 0; j <= ind; ++j) {
                nowans += a[ord[i]][ord[j]];
            }
        }
        ans[ind] = nowans;
    }
    reverse(ans, ans + n);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}