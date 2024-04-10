#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        arr[n] = 1;
        int l = -1, r = n;
        int ans = 0;
        while (true) {
            l++;
            while (arr[l] == 0) l++;
            r--;
            while (r >= 0 && arr[r] == 1) r--;
            if (l >= r) break;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}