#include <bits/stdc++.h>
using namespace std;

const int MAXK = 2000;
int tests[MAXK];
pair<int, int> arr[MAXK];
bool ans[MAXK];

main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> tests[i];
    }
    for (int i = 0; i < min(n, k); ++i) {
        arr[i] = {i, 0};
    }
    int nowd = 0;
    int cnt = 0;
    int nowi = k;
    for (int t = 1; t <= n * 150; ++t) {
        vector<pair<int, int>> ts(k);
        for (int i = 0; i < k; ++i) {
            arr[i].second++;
            ts[i] = arr[i];
            if (arr[i].second == tests[arr[i].first]) {
                arr[i] = {nowi, 0};
                nowi++;
                cnt++;
            }
        }
        int newd = 100 * (double)cnt / n + 0.5;
        for (int i = 0; i < k; ++i) {
            if (ts[i].second == nowd) {
                ans[ts[i].first] = true;
            }
        }
        nowd = newd;
    }
    int ansint = 0;
    for (int i = 0; i < n; ++i) {
        if (ans[i]) {
            ansint++;
        }
    }
    cout << ansint;
    return 0;
}