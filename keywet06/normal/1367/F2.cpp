#include <bits/stdc++.h>

const int N = 1e6 + 10;

int n;
int a[N], pref[N];

std::vector<int> by[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        std::vector<int> v;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            v.emplace_back(a[i]);
        }
        std::sort(v.begin(), v.end());
        v.erase(std::unique(v.begin(), v.end()), v.end());
        for (int i = 1; i <= n + 5; ++i) {
            by[i].clear();
            pref[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            a[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        }
        std::vector<int> vals;
        for (int i = 1; i <= n; ++i) {
            vals.emplace_back(a[i]);
            by[a[i]].emplace_back(i);
        }
        std::sort(vals.begin(), vals.end());
        vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
        int best = n;
        int r = 0;
        pref[0] = 0;
        for (int i = 0; i < vals.size(); ++i)
            pref[i + 1] = pref[i] + by[vals[i]].size();
        for (int i = 0; i < vals.size(); ++i) {
            best = std::min(best, n - (int)by[vals[i]].size());
            r = std::max(r, i);
            while (r + 1 < vals.size() &&
                   by[vals[r + 1]][0] >= by[vals[r]].back())
                ++r;
            int tot = pref[r + 1] - pref[i];
            if (i > 0) {
                int c =
                    std::lower_bound(by[vals[i - 1]].begin(),
                                     by[vals[i - 1]].end(), by[vals[i]][0]) -
                    by[vals[i - 1]].begin();
                tot += c;
            }
            if (r + 1 < vals.size()) {
                int c = std::lower_bound(by[vals[r + 1]].begin(),
                                         by[vals[r + 1]].end(),
                                         by[vals[r]].back()) -
                        by[vals[r + 1]].begin();
                tot += by[vals[r + 1]].size() - c;
            }
            best = std::min(best, n - tot);
        }
        for (int i = 0; i + 1 < vals.size(); ++i) {
            for (int sz_pref = 1; sz_pref <= by[vals[i]].size(); ++sz_pref) {
                int c = std::lower_bound(by[vals[i + 1]].begin(),
                                         by[vals[i + 1]].end(),
                                         by[vals[i]][sz_pref - 1]) -
                        by[vals[i + 1]].begin();
                int tot = (int)by[vals[i + 1]].size() - c + sz_pref;
                best = std::min(best, n - tot);
            }
        }
        std::cout << best << '\n';
    }
    return 0;
}