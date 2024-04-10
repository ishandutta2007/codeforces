#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1E9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a.back() = INF + 1;
    int m;
    cin >> m;
    multiset<int> c;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        c.insert(b[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    vector<pair<int, int>> f {{0, -1}};
    vector<int> len(n + 2);
    for (int i = 1; i <= n + 1; ++i) {
        if (a[i] != -1) {
            if (f.back().first < a[i]) {
                len[i] = (int)f.size();
                f.emplace_back(a[i], i);
            } else {
                len[i] = lower_bound(f.begin(), f.end(), make_pair(a[i], -1)) - f.begin();
                f[len[i]] = {a[i], i};
            }
        } else {
            for (auto j = (int)b.size() - 1, k = (int)f.size(); j >= 0; --j)  {
                while (k > 0 && f[k - 1].first >= b[j])
                    --k;
                if (k == (int)f.size())
                    f.emplace_back(b[j], -1);
                else
                    f[k] = {b[j], -1};
            }
        }
    }
    for (int i = n + 1; i > 0; ) {
        for (int j = i - 1, cnt = 0; j >= 0; --j) {
            if (a[j] == -1) {
                ++cnt;
                continue;
            }
            if (a[j] >= a[i])
                continue;
            int l = upper_bound(b.begin(), b.end(), a[j]) - b.begin();
            int r = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            if (min(r - l, cnt) == len[i] - len[j] - 1) {
                auto it = c.find(b[l]);
                cnt = min(cnt, r - l);
                for (int k = j + 1; k < i && cnt > 0; ++k) {
                    if (a[k] == -1) {
                        a[k] = *it;
                        c.erase(it);
                        it = c.upper_bound(a[k]);
                        --cnt;
                    }
                }
                i = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            a[i] = *c.begin();
            c.erase(c.begin());
        }
        cout << a[i] << " \n"[i == n];
    }
    return 0;
}