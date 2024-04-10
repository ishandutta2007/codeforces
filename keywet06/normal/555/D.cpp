#include <bits/stdc++.h>

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        std::vector<int> x(n);
        for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
        std::vector<std::pair<int, int> > a;
        for (int i = 0; i < n; ++i) a.push_back(std::make_pair(x[i], i));
        std::sort(a.begin(), a.end());
        std::vector<int> o(n);
        for (int i = 0; i < n; ++i) o[a[i].second] = i;
        for (int it = 0; it < m; ++it) {
            int id, len;
            scanf("%d %d", &id, &len);
            id = o[--id];
            int last = -1;
            while (1) {
                int ii =
                    std::lower_bound(a.begin(), a.end(), std::make_pair(a[id].first + len + 1, -1)) - a.begin() - 1;
                int nxt = -1;
                if (ii > id) {
                    nxt = ii;
                } else {
                    ii = std::lower_bound(a.begin(), a.end(), std::make_pair(a[id].first - len, -1)) - a.begin();
                    if (ii >= id) break;
                    nxt = ii;
                }
                if (nxt == last) {
                    len %= 2 * abs(a[id].first - a[nxt].first);
                    last = -1;
                    continue;
                }
                len -= abs(a[id].first - a[nxt].first);
                last = id;
                id = nxt;
            }
            printf("%d\n", a[id].second + 1);
        }
    }
    return 0;
}