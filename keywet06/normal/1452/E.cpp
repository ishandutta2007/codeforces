#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> l(m), r(m);
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i];
        --l[i];
    }
    int ans = 0;
    for (int i = 0; i <= n - k; ++i) {
        vector<int> da(n + 1, 0);
        vector<int> db(n + 1, 0);
        for (int j = 0; j < m; ++j) {
            int cnt = max(min(r[j], i + k) - max(l[j], i), 0);
            if (cnt == k) {
                db[0] += k;
                db[n] -= k;
            } else if (r[j] - l[j] >= k) {
                if (l[j] >= k - cnt) {
                    db[0] += cnt;
                    db[l[j] - k + cnt] -= cnt;
                    ++da[l[j] - k + cnt];
                    --da[l[j]];
                    db[l[j] - k + cnt] += k - l[j];
                    db[l[j]] -= k - l[j];
                } else {
                    ++da[0];
                    --da[l[j]];
                    db[0] += k - l[j];
                    db[l[j]] -= k - l[j];
                }
                db[l[j]] += k;
                db[r[j] - k] -= k;
                --da[r[j] - k];
                ++da[r[j] - cnt];
                db[r[j] - k] += r[j];
                db[r[j] - cnt] -= r[j];
                db[r[j] - cnt] += cnt;
                db[n] -= cnt;
            } else {
                if (l[j] >= k - cnt) {
                    db[0] += cnt;
                    db[l[j] - k + cnt] -= cnt;
                    ++da[l[j] - k + cnt];
                    --da[r[j] - k];
                    db[l[j] - k + cnt] += k - l[j];
                    db[r[j] - k] -= k - l[j];
                    db[r[j] - k] += r[j] - l[j];
                    db[l[j]] -= r[j] - l[j];
                } else if (r[j] >= k) {
                    ++da[0];
                    --da[r[j] - k];
                    db[0] += k - l[j];
                    db[r[j] - k] -= k - l[j];
                    db[r[j] - k] += r[j] - l[j];
                    db[l[j]] -= r[j] - l[j];
                } else {
                    db[0] += r[j] - l[j];
                    db[l[j]] -= r[j] - l[j];
                }
                --da[l[j]];
                ++da[r[j] - cnt];
                db[l[j]] += r[j];
                db[r[j] - cnt] -= r[j];
                db[r[j] - cnt] += cnt;
                db[n] -= cnt;
            }
        }
        for (int j = 1; j <= n; ++j) {
            da[j] += da[j - 1];
            db[j] += db[j - 1];
        }
        for (int j = 0; j <= n; ++j) {
            ans = max(ans, da[j] * j + db[j]);
        }
    }
    cout << ans << endl;
    return 0;
}