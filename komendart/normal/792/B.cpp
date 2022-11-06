#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    vector<char> used(n);
    vector<int> ans;
    int cur = 0;
    for (int i = 0; i < k; ++i) {
        int d = a[i] % (n - i);
        while (d > 0) {
            cur = (cur + 1) % n;
            if (!used[cur]) --d;
        }
        ans.push_back(cur);
        used[cur] = true;
        while (used[cur]) {
            cur = (cur + 1) % n;
        }
    }

    for (auto i: ans) {
        cout << i + 1 << ' ';
    }
}