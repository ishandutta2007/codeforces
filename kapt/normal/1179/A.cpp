#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 1e5;
pair<int, int> ans[MAXN];

main() {
    int n, q;
    cin >> n >> q;
    deque<int> arr;
    int mx = -1, mi = -1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.push_back(x);
        if (x > mx) {
            mx = x;
            mi = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        ans[i] = {arr[0], arr[1]};
        int x = arr[0], y = arr[1];
        arr.pop_front();
        arr.pop_front();
        if (x < y) {
            swap(x, y);
        }
        arr.push_front(x);
        arr.push_back(y);
    }
    for (int i = 0; i < q; ++i) {
        int m;
        cin >> m;
        if (m <= n) {
            cout << ans[m - 1].first << " ";
            cout << ans[m - 1].second << "\n";
        } else {
            m %= (n - 1);
            int ind = (m + n - 2) % (n - 1);
            if (ind == 0) {
                ind = n - 1;
            }
            cout << arr[0] << " " << arr[ind] << endl;
        }
    }
    return 0;
}