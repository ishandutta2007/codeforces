#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    if ((int) b.size() == n) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        a[i] = (int) (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
    }
    int ans = 0;
    vector<int> mark(n, 0);
    for (int i = 0; i < n; i++) {
        int take = 0;
        for (int j = 0; j < n; j++) {
            if (mark[a[n - 1 - j]] > 0) {
                break;
            }
            mark[a[n - 1 - j]] = 1;
            ++take;
        }
        ans = max(ans, i + take);
        for (int j = 0; j < take; j++) {
            mark[a[n - 1 - j]] = 0;
        }
        if (mark[a[i]]) {
            break;
        }
        mark[a[i]] = 1;
    }
    cout << n - ans << '\n';
    return 0;
}