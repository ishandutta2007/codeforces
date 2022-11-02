#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 1e6;
int a[MAXN], b[MAXN], b1[MAXN];

main() {
    int m, k, n, s;
    cin >> m >> k >> n >> s;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        a[i]--;
    }
    int sum = 0;
    unordered_set<int> need;
    for (int i = 0; i < s; ++i) {
        int x;
        cin >> x;
        x--;
        need.insert(x);
        b[x]++;
        if (b[x] == 1) {
            sum++;
        }
    }
    copy(b, b + MAXN, b1);
    int l = 0;
    int r = 0;
    b[a[0]]--;
    if (b[a[0]] == 0) {
        sum--;
    }
    deque<int> inds;
    bool f = false;
    while (l < m) {
        while (r < m) {
            // cout << l << " " << r << " " << sum << endl;
            if (sum == 0) {
                break;
            }
            r++;
            if (r < m && need.count(a[r])) {
                b[a[r]]--;
                if (b[a[r]] == 0) {
                    sum--;
                }
            }
        }
        if (sum == 0) {
            if (n * k + r + 1 - (l / k + 1) * k <= m || l / k + 1 >= n) {
                f = true;
                break;
            }
        }
        if (l < m && need.count(a[l])) {
            b[a[l]]++;
            if (b[a[l]] == 1) {
                sum++;
            }
        }
        l++;
    }
    if (f) {
        // cout << l << " " << r << endl;
        for (int i = l; i <= r; ++i) {
            if (b1[a[i]] > 0) {
                b1[a[i]]--;
                inds.push_back(i);
            }
        }
        vector<int> ansarr;
        for (int i = min(l / k * k, (n - 1) * k); i < r; ++i) {
            if (inds[0] != i) {
                ansarr.push_back(i);
            } else {
                inds.pop_front();
            }
        }
        cout << max(r - (l / k * k + k - 1), (int64_t)0) << endl;
        for (int i = 0; i < r - (l / k * k + k - 1); ++i) {
            /*if (i >= ansarr.size()) {
                return 0;
            }*/
            cout << ansarr[i] + 1 << " ";
        }
    } else {
        cout << -1;
    }
    return 0;
}