#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, s;
    cin >> n >> s;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int flag = 0;
    if (a[s] != 0) {
        flag++;
        a[s] = 0;
    }
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }

    int val = n + 5;
    int more = n - 1;
    int zero = 0;
    for (int h = 1; h < n; h++) {
        if (!cnt[h]) zero++;
        else more -= cnt[h];
        val = min(val, max(more, zero));
    }
    if (val == n + 5) val = 0;

    cout << flag + val << '\n';
}