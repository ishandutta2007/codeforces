#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int maxn = 4e5;
int arr[maxn], prefs[maxn], oprefs[maxn];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        int cnt = 0;
        while (arr[i] > 0) {
            cnt += arr[i] % 2;
            arr[i] /= 2;
        }
        arr[i] = cnt;
        prefs[i + 1] = prefs[i] + arr[i];
        oprefs[i + 1] = oprefs[i];
        if (prefs[i + 1] % 2 == 0) {
            oprefs[i + 1]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int s = 0;
        int m = 0;
        for (int j = i; j < n; ++j) {
            s += arr[j];
            m = max(m, arr[j]);
            if (s >= 140) {
                if (prefs[i] % 2 == 0) {
                    ans += oprefs[n] - oprefs[j];
                } else {
                    ans += (n - j) - (oprefs[n] - oprefs[j]);
                }
                // ans += n - j;
                break;
            }
            if (s % 2 == 0 && m * 2 <= s) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}