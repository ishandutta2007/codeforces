#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5;
int arr[MAXN], cnt[MAXN], used[MAXN];
int g[MAXN];

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        fill(cnt, cnt + n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            arr[i]--;
            int k = (i - arr[i] + n) % n;
            cnt[k]++;
        }
        vector<int> ans;
        for (int d = 0; d < n; ++d) {
            if (cnt[d] < n - 2 * m) continue;
            for (int i = 0; i < n; ++i) {
                used[i] = 0;
            }
            for (int i = 0; i < n; ++i) {
                g[arr[i]] = (i - d + n) % n;
            }
            int k = 0;
            for (int i = 0; i < n; ++i) {
                if (!used[i]) {
                    int c = i;
                    while (!used[c]) {
                        used[c] = 1;
                        c = g[c];
                    }
                    k++;
                }
            }
            if (k >= n - m) {
                ans.push_back(d);
            }
        }
        cout << ans.size() << " ";
        for (auto elem : ans) {
            cout << elem << " ";
        }
        cout << "\n";
    }
    return 0;
}