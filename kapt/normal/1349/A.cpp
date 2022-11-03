#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5 + 10, INF = 1e9;
int arr[MAXN];
int num[MAXN];
array<int, 2> prm[MAXN];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < MAXN; ++i) {
        prm[i] = {INF, INF};
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        for (int j = 2; j * j <= arr[i]; ++j) {
            int cnt = 0;
            if (arr[i] % j == 0) {
                num[j]++;
            } else {
                continue;
            }
            while (arr[i] % j == 0) {
                arr[i] /= j;
                cnt++;
            }
            if (prm[j][0] >= cnt) {
                prm[j][1] = prm[j][0];
                prm[j][0] = cnt;
            } else if (prm[j][1] >= cnt) {
                prm[j][1] = cnt;
            }
        }
        if (arr[i] != 1) {
            num[arr[i]]++;
            if (prm[arr[i]][0] >= 1) {
                prm[arr[i]][1] = prm[arr[i]][0];
                prm[arr[i]][0] = 1;
            } else if (prm[arr[i]][1] >= 1) {
                prm[arr[i]][1] = 1;
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < MAXN; ++i) {
        if (num[i] <= n - 2) {
            continue;
        } else if (num[i] == n - 1) {
            if (prm[i][0] >= 0) {
                prm[i][1] = prm[i][0];
                prm[i][0] = 0;
            } else if (prm[i][1] >= 0) {
                prm[i][1] = 0;
             }
        }
        for (int j = 0; j < prm[i][1]; ++j) {
            ans *= i;
        }
    }
    cout << ans;
    return 0;
}