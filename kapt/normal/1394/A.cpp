#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 1e5;
int upref[MAXN], lpref[MAXN];

main() {
    int n, d, m;
    cin >> n >> d >> m;
    vector<int> low, up;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x > m) {
            up.push_back(x);
        } else {
            low.push_back(x);
        }
    }
    sort(up.begin(), up.end());
    reverse(up.begin(), up.end());
    sort(low.begin(), low.end());
    reverse(low.begin(), low.end());
    int usz = up.size();
    for (int i = 0; i < (int)low.size(); ++i) {
        lpref[i + 1] = lpref[i] + low[i];
    }
    for (int i = 0; i < (int)up.size(); ++i) {
        upref[i + 1] = upref[i] + up[i];
    }
    int ans = 0;
    for (int k = 0; k <= min(usz, (n + d) / (d + 1)); ++k) {
        int res = upref[k];
        int x = usz - k;
        if (x > k * d) {
            continue;
        }
        if (k == 0) {
            cout << lpref[n];
            return 0;
        }
        int y = n - (k - 1) * (d + 1) - 1 - max((int64_t)0, x - (k - 1) * d);
        res += lpref[y];
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}